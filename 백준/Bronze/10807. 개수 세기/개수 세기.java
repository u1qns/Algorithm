import java.io.*;
import java.text.BreakIterator;
import java.util.*;



public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));        
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        int target, answer = 0;

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; ++i)
            arr[i] = Integer.parseInt(st.nextToken());

        target = Integer.parseInt(br.readLine());
        for(int i=0; i<N; ++i) {
            if(arr[i] == target)
                ++answer;
        }

        System.out.print(answer);

    } // main
}