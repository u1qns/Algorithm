import java.util.*;

class Solution {
    public class Node {
        int al, co, cost;
        Node(final int al, final int co, final int cost) {
            this.al = al;
            this.co = co;
            this.cost = cost;
        }
    };
    
    public int solution(int alp, int cop, int[][] problems) {

        int[][] dp = new int[151][151];

        int max_al = 0, max_co = 0;
        for(int[] p : problems) {
            max_al = Math.max(max_al, p[0]);
            max_co = Math.max(max_co, p[1]);
        }
        int[][] study = {{0, 0, 1, 0, 1}, {0, 0, 0, 1, 1}};

        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.cost, b.cost));
        pq.offer(new Node(alp, cop, 0));
        
        while(!pq.isEmpty()) {
            Node now = pq.poll();
            
            if(dp[now.al][now.co] != 0 && dp[now.al][now.co] < now.cost) continue;

            for(final int[] p : problems) {
                
                if(p[0] > now.al || p[1] > now.co) continue;

                Node next = new Node(
                    Math.min(max_al, now.al + p[2]),
                    Math.min(max_co, now.co + p[3]),
                    now.cost + p[4]
                );

                if (dp[next.al][next.co] == 0
                    || dp[next.al][next.co] > next.cost)
                {
                    dp[next.al][next.co] = next.cost;
                    pq.offer(next);
                }
            }

            for(final int[] p : study) {

                if(p[0] > now.al || p[1] > now.co) continue;

                Node next = new Node(
                    Math.min(max_al, now.al + p[2]),
                    Math.min(max_co, now.co + p[3]),
                    now.cost + p[4]
                );

                if (dp[next.al][next.co] == 0
                    || dp[next.al][next.co] > next.cost)
                {
                    dp[next.al][next.co] = next.cost;
                    pq.offer(next);
                }
            }
             
        }
        
        return dp[max_al][max_co];
    }
}