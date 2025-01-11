import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()); // 책 수
            int M = Integer.parseInt(st.nextToken()); // 학생 수

            // 학생들의 요청 저장
            int[][] requests = new int[M][2];
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                requests[i][0] = Integer.parseInt(st.nextToken()); // a
                requests[i][1] = Integer.parseInt(st.nextToken()); // b
            }

            Arrays.sort(requests, (r1, r2) -> {
                if (r1[1] == r2[1]) return r1[0] - r2[0];
                return r1[1] - r2[1];
            });

            boolean[] assigned = new boolean[N + 1];
            int count = 0;

            for (int[] request : requests) {
                int a = request[0];
                int b = request[1];

                for (int i = a; i <= b; i++) {
                    if (!assigned[i]) {
                        assigned[i] = true;
                        count++;
                        break;
                    }
                }
            }

            sb.append(count).append("\n");
        }

        System.out.print(sb);
    }
}
