import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int[] arr = new int[N+1];
        int[] dp = new int[N+1];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for(int i=1; i<=N; ++i) {
            dp[i] = Math.abs(arr[i]-arr[0]);
            for(int j=i-1; j>=1; --j) {

                dp[i] = Math.max(Math.abs(arr[i]-arr[j]) + dp[j-1],
                                    dp[i]);
                dp[i] = Math.max(dp[i], dp[j]);
            }
        }

        System.out.println(dp[N-1]);

    } // main
}