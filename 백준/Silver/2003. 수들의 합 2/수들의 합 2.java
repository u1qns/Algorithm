import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int answer = 0;
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] prefix = new int[N+1];
    
        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=N; ++i) {
            prefix[i] += prefix[i-1] + Integer.parseInt(st.nextToken());
            for(int j=i-1; j>=0; --j) {
                if(prefix[j] < prefix[i] - M)
                    break;
                    
                if(prefix[i] - prefix[j] == M)
                    ++answer;
            }
        }
        
        System.out.print(answer);
    } // main
}
