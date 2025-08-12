import java.io.*;
import java.util.*;

public class Main {

    static int distance(int x1, int y1, int x2, int y2) {
        return Math.abs(x2 - x1) + Math.abs(y2 - y1);
    }

    static int distance(final int[] a, final int[] b) {
        return distance(a[0], a[1], b[0], b[1]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            
            boolean answer = false;

            int N = Integer.parseInt(br.readLine());
            List<int[]> nodes = new ArrayList<>();

            for (int i = 0; i < N + 2; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                nodes.add(new int[]{x, y});
            }

            Queue<Integer> q = new ArrayDeque<>();
            q.offer(0);
            
            boolean[] visited = new boolean[N + 2];
            visited[0] = true;


            while (!q.isEmpty()) {
                int front = q.poll();
                if (front == N + 1) {
                    answer = true;
                    break;
                }
                
                for (int i=0; i<N+2; ++i) {
                    if (!visited[i] && distance(nodes.get(front), nodes.get(i)) <= 1000) {
                        visited[i] = true;
                        q.offer(i);
                    }
                }
            }

            System.out.println(answer ? "happy" : "sad");
        }
    }
}