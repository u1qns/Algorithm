import java.io.*;
import java.util.*;

public class Main {

    final static int MAX_RANGE = 100 + 1;
    final static int DIRECTION = 4;

    // 동쪽이 1, 서쪽이 2, 남쪽이 3, 북쪽이 4 
    final static int[] dx = {0, 0, 1, -1};
    final static int[] dy = {1, -1, 0, 0};


    static int M = 0, N = 0;
    static int[][] grid = new int[MAX_RANGE][MAX_RANGE];
    static int[][][] dp = new int[DIRECTION][MAX_RANGE][MAX_RANGE];

    static int rotation(final int dir, final int idx) {
        if(dir < 2)
            return (idx == 0 ? 2 : 3);
        else
            return (idx == 0 ? 0 : 1);
    }

    static boolean isValid(final int x, final int y) {
        if(x < 0 || y < 0 || x>=M || y>=N)
            return false;
        return true;
    }

    static class Pair {
        Pair(final int x, final int y, final int d, final int cost) {
            this.x = x;
            this.y = y;
            this.d = d;
            this.cost = cost;
        }        
        
        int x, y, d, cost;
    }

    static int solve(final Pair start, final Pair end) {

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.cost, b.cost));
        pq.offer(start);

        dp[start.d][start.x][start.y] = 0;

        while(!pq.isEmpty()) {
            Pair now = pq.poll();

            if(dp[now.d][now.x][now.y] < now.cost)
                continue;

            // 명령 1 
            for(int len=1; len <=3; ++len) {
                
                int x = now.x + (dx[now.d]*len);
                int y = now.y + (dy[now.d]*len);

                // len 1, 2, 3 중에 범위 벗어나거나 1 만나면 아예 못 가니까 break로 방향 전환시킴
                if(!isValid(x, y) || grid[x][y] == 1) break;

                int next_cost = dp[now.d][now.x][now.y] + 1;
                if(next_cost >= dp[now.d][x][y]) continue;

                pq.offer(new Pair(x, y, now.d, next_cost));
                dp[now.d][x][y] = next_cost;
            }

            //명령 2
            for(int i=0; i<2 ; ++i) {
                int dir = rotation(now.d, i);
                int next_cost = dp[now.d][now.x][now.y] + 1;

                if(next_cost >= dp[dir][now.x][now.y]) continue;

                pq.offer(new Pair(now.x, now.y, dir, next_cost));
                dp[dir][now.x][now.y] =  next_cost;
            }
        }

        return dp[end.d][end.x][end.y];
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));        
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        for(int i=0; i<M; ++i) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<N; ++j) {
                grid[i][j] = Integer.parseInt(st.nextToken());
                // dp 초기화
                for(int d=0; d<4; ++d) {
                    dp[d][i][j] = Integer.MAX_VALUE;
                }
            }
        }

        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        Pair start = new Pair(x-1, y-1, d-1, 0);

        st = new StringTokenizer(br.readLine());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        Pair end = new Pair(x-1, y-1, d-1, 0);

        System.out.print(solve(start, end));
    } // main
}