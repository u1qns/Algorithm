import java.io.*;
import java.util.*;

public class Main {

    static int DAYS[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    static int trans(final int month, final int day) {
        return DAYS[month - 1] + day;
    }

    static PriorityQueue<int[]> flowers = new PriorityQueue<>((a, b) -> 
        a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(a[0], b[0])
    );

    static int solve(final int start, final int end) {
        int answer = 0;
        int now = start;

        while(!flowers.isEmpty() && now <= end) {
            int max_end = -1;

            while(!flowers.isEmpty() && now >= flowers.peek()[0]) {
                max_end = Math.max(max_end, flowers.poll()[1]);
            }

            if(max_end == -1) {
                return 0;
            }

            ++answer;
            now = max_end;
        }

        return now < 335 ? 0 : answer;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 1; i < 13; ++i) {
            DAYS[i] += DAYS[i - 1];
        }

        int ts = trans(3, 1);
        int te = trans(11, 30);
        int N = Integer.parseInt(st.nextToken());  

        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            int start = trans(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            int end = trans(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            flowers.offer(new int[]{start, end});
        }
    
        System.out.print(solve(ts, te));
    }
}