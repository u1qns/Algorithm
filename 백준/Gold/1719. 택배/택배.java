import java.util.*;
import java.io.*;

class Main
{
    static int N;
    static List<List<Pair>> adj;
    static int[][] answer;

    static void dijkstra(final int start) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.cost, b.cost));
        pq.offer(new Pair(0, start));

        int[] dp = new int[N+1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[start] = 0;

        int[] route = new int[N+1];

        while(!pq.isEmpty()) {
            Pair top = pq.poll();

            if(dp[top.node] < top.cost) continue;

            for(final Pair next : adj.get(top.node)) {
                int next_cost = dp[top.node] + next.cost;
                if(dp[next.node] > next_cost) {
                    dp[next.node] = next_cost;
                    route[next.node] = top.node;
                    pq.offer(new Pair(dp[next.node], next.node));
                }
            }
        }

        for(int i=1; i<=N; ++i) {
            answer[i][start] = route[i];
        }
    }


    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        adj = new ArrayList<>();
        answer = new int[N+1][N+1];

        for(int i=0; i<=N; ++i) {
            adj.add(new ArrayList<>());
            Arrays.fill(answer[i], -1);
        }

        for(int i=0; i<M; ++i) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            adj.get(from).add(new Pair(cost, to));
            adj.get(to).add(new Pair(cost, from));
        }

        for(int start=1; start<=N; ++start) {
            dijkstra(start);
        }

        for(int i=1; i<=N; ++i) {
            for(int j=1; j<=N; ++j) {
                if(i == j || answer[i][j] == -1) {
                    sb.append("-");
                } else {
                    sb.append(answer[i][j]);
                }
                sb.append(" ");
            }
            sb.append("\n");
        }

        System.out.print(sb.toString());
    } // main

    static class Pair {
        int cost, node;

        public Pair(int cost, int node) {
            this.cost = cost;
            this.node = node;
        }
    }
}