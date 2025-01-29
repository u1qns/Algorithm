import java.io.*;
import java.util.*;

public class Main {
    

    static int solve(int[][] adj, int N, int start, int end) {

        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.weight, b.weight));
        pq.offer(new Node(start, 0));

        int[] dp = new int[N+1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[start] = 0;

        int[] route = new int[N+1];

        while(!pq.isEmpty()) {
            Node top = pq.poll();

            if(top.weight > dp[top.idx])
                continue;

            for(int next=1; next<=N; ++next) {

                if(adj[top.idx][next] == 0)
                    continue;

                int next_cost = top.weight + adj[top.idx][next];
                if(next_cost >= dp[next]) 
                    continue;
                
                dp[next] = next_cost;
                pq.offer(new Node(next, next_cost));

                route[next] = top.idx;
            }

        }


        int tmp = adj[end][route[end]];
        for(int i=route[end]; route[i] != 0; i=route[i]) {
            tmp = Integer.max(tmp, adj[i][route[i]]);
            //System.out.println(tmp);
        }

        return dp[end] - tmp;
    }


    // 다익스트라에서 그 경로의 최대를 빼면 안되나? 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int[][] adj = new int[N+1][N+1];
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        for(int i=1; i<N; ++i) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            adj[from][to] = adj[to][from] = weight;
        }
        
        int answer = solve(adj, N, start, end);

        System.out.print(answer);
    
    } // main

    static class Node {

        Node(int idx, int weight) {
            this.idx = idx;
            this.weight = weight;
        }

        int idx, weight;

    }
}