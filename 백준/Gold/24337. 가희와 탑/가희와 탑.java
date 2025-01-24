import java.io.*;
import java.util.*;

public class Main {
    static Deque<Integer> getAnswer(final int N, int a, int b) {
        Deque<Integer> answer = new ArrayDeque<>();
        if (a + b > N + 1)
            return answer; 

        for (int i=1; i<a; ++i)
            answer.add(i);
        answer.add(Math.max(a, b));
        for (int i=b-1; i>0; --i)
            answer.add(i);
            
        int front = answer.getFirst();        
        answer.removeFirst();

        int sz = answer.size();
        for(int i=1; i<N-sz; ++i)
            answer.offerFirst(1);
        answer.offerFirst(front);
        
        return answer;
     }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        if (a + b > N +1) {
            System.out.print(-1);
            return;
        }
        
        Deque<Integer> answer = getAnswer(N, a, b);
        for (int ans : answer)
            sb.append(ans).append(" ");

        System.out.print(sb);
        
    } // main
}