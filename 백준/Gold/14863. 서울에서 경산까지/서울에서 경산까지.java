import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[][] DP = new int[N][K+1];
        for (int[] row : DP) Arrays.fill(row, -1); // 초기값 -1 (불가능 상태)
        
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int bt = Integer.parseInt(st.nextToken());
            int bc = Integer.parseInt(st.nextToken());
            int wt = Integer.parseInt(st.nextToken());
            int wc = Integer.parseInt(st.nextToken());

            if (i == 0) {
                if (bt <= K) DP[0][bt] = Math.max(DP[0][bt], bc);
                if (wt <= K) DP[0][wt] = Math.max(DP[0][wt], wc);
            } else {
                for (int j = 0; j <= K; j++) {
                    if (DP[i-1][j] == -1) continue;
                    if (j + bt <= K) DP[i][j+bt] = Math.max(DP[i][j+bt], DP[i-1][j] + bc);
                    if (j + wt <= K) DP[i][j+wt] = Math.max(DP[i][j+wt], DP[i-1][j] + wc);
                }
            }
        }

        int ans = 0;
        for (int t = 0; t <= K; t++) ans = Math.max(ans, DP[N-1][t]);
        System.out.println(ans);
    }
}