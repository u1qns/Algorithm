import java.io.*;
import java.util.*;

public class Main {
    static int N = 0;
    static List<List<Integer>> arr = new ArrayList<>();

    static int solve(int idx) {
        int result = 0;

        int sz = arr.get(idx).size();
        if(sz == 0) return 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(final int c : arr.get(idx)) {
            pq.offer(solve(c));
        }

        for(int i=0; i<sz; ++i) {
            result = Math.max(result, pq.poll() + i + 1);
        }

        return result;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int answer = 0;
        N = Integer.parseInt(br.readLine());
        for(int i=0; i<N; ++i)
            arr.add(new ArrayList<>());
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int inp = Integer.parseInt(st.nextToken());
        for(int i=1; i<N; ++i) {
            inp = Integer.parseInt(st.nextToken());
            arr.get(inp).add(i);
        }

        answer = solve(0);
        System.out.print(answer);
    }
}