import java.io.*;
import java.util.*;

public class Main {

    static int solve(List<List<Node>> adj, int N, int start, int end) {

        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.weight, b.weight));
        pq.offer(new Node(start, 0));

        int[] dp = new int[N + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[start] = 0;

        int[] route = new int[N + 1];

        while (!pq.isEmpty()) {
            Node top = pq.poll();

            if (top.weight > dp[top.idx])
                continue;

            for (Node next : adj.get(top.idx)) {

                int next_idx = next.idx;
                int next_cost = top.weight + next.weight;

                if (next_cost >= dp[next_idx])
                    continue;

                dp[next_idx] = next_cost;
                pq.offer(new Node(next_idx, next_cost));

                route[next_idx] = top.idx;
            }
        }

        int tmp = 0;
        for (int i = end; route[i] != 0; i = route[i]) {
            for (Node next : adj.get(route[i])) {
                if (next.idx == i) {
                    tmp = Integer.max(tmp, next.weight);
                    break;
                }
            }
        }

        return dp[end] - tmp;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        List<List<Node>> adj = new ArrayList<>();
        for (int i = 0; i <= N; ++i) {
            adj.add(new ArrayList<>());
        }

        for (int i = 1; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            adj.get(from).add(new Node(to, weight));
            adj.get(to).add(new Node(from, weight));
        }

        int answer = solve(adj, N, start, end);
        System.out.print(answer);
    }

    static class Node {
        int idx, weight;

        Node(int idx, int weight) {
            this.idx = idx;
            this.weight = weight;
        }
    }
}
