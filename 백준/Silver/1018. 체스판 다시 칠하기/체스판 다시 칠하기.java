import java.io.*;
import java.util.*;
public class Main {
    final static String[] patterns = {"WBWBWBWB", "BWBWBWBW"};
    static char[][] input;
    static int answer = Integer.MAX_VALUE;

    static void repainting(int r, int c ){

        int idx = 0;
        int cnt1 = 0, cnt2 = 0;

        for(int i=r; i<r+8; ++i) {
            int patternIdx1 = (i%2 ==0 ? 0 : 1);
            int patternIdx2 = (i%2 ==0 ? 1 : 0);

            for (int j = c; j < c + 8; ++j) {

                //패턴1
                if(!(input[i][j] == patterns[patternIdx1].charAt(idx)))
                    ++cnt1;

                //패턴2
                if(!(input[i][j] == patterns[patternIdx2].charAt(idx)))
                    ++cnt2;


                ++idx;
            }
            idx = 0;
        }

        answer = (answer < cnt1 ? answer : cnt1);
        answer = (answer < cnt2 ? answer : cnt2);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        input = new char[N][M];
        for(int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine());
            input[i] = st.nextToken().toCharArray();
        }

        for(int i=0; i<N-7; ++i) {
            for(int j=0; j<M-7; ++j) {
                repainting(i, j);
            }
        }

        System.out.print(answer);

    }
}