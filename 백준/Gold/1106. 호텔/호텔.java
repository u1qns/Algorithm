import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int answer = Integer.MAX_VALUE;
        int C = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        List<int[]> info = new ArrayList<>();
        int[] dp = new int[C+101];
        Arrays.fill(dp, Integer.MAX_VALUE);

        for(int i=0; i<N; ++i)
        {
            st = new StringTokenizer(br.readLine());
            int cost = Integer.parseInt(st.nextToken());
            int profit = Integer.parseInt(st.nextToken());
            info.add(new int[]{cost, profit});
            dp[profit] = Math.min(dp[profit], cost);
        }

        for(int p=0; p<C+101; ++p)
        {
            for(int i=0; i<N; ++i)
            {
                int cost = info.get(i)[0];
                int profit = info.get(i)[1];

                if(p < profit) continue;

                if (dp[p - profit] != Integer.MAX_VALUE) {
                    dp[p] = Math.min(dp[p], dp[p - profit] + cost);
               }
            }

            if (p >= C)
                answer = Math.min(answer, dp[p]);
        }

        System.out.print(answer);

    } // main
}