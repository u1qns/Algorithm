import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        List<Integer>[] adj = new ArrayList[N+1];
        int[] result = new int[N+1];

        for (int i = 0; i <= N; ++i) {
            adj[i] = new ArrayList<>();
        }

        for(int i=0; i<M; ++i) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            adj[A].add(B);
        }

        for(int idx=1; idx<=N; ++idx) {
            boolean visited[] = new boolean[N+1];

            Queue<Integer> q = new ArrayDeque<>();
            q.offer(idx);

            visited[idx] = true;
            while(!q.isEmpty()){
                int cur = q.poll();
                for(int i : adj[cur]) {
                    if(visited[i]) continue;
                    visited[i] = true;
                    result[i]++;
                    q.offer(i);
                }
            }

        }

        int answer = 0;
        for(int i=1; i<=N; ++i) {
            answer = Math.max(answer, result[i]);
        }

        for(int i=1; i<=N; ++i) {
            if(answer != result[i]) continue;
            sb.append(i).append(" ");
        }
        System.out.print(sb.toString());
    }

}