import java.io.*;
import java.util.*;

public class Main {
    static Deque<Integer> getAnswer(final int N, int a, int b) {

        Deque<Integer> answer = new ArrayDeque<>();
        if (a + b > N + 1) {
            return answer; 
            // 5 100 1 이라고 생각해보자. 건물 5개 있는데 100개 보이고 싶다? 미친거지..
            // 5 3 3  => 1 2 3 2 1 => a+b가 N + 1까지는 괜찮다.
            // 5 3 4 => 여기서 부터 안된다. 
        }

        // A 구역 만들기
        for (int i=1; i<a; ++i) {
            answer.add(i);
        }
        
        // Max Height 건물 세우기
        answer.add(Math.max(a, b));

        // B 구역 만들기
        for (int i=b-1; i>0; --i) {
            answer.add(i);
        }

        // 사전순 증가대로 N개의 건물 수 맞추기
        // - a의 맨 앞을 어디에 보관한다. 
        // 물론 사전순 증가이기 때문에 맨 앞 1 인데 왜 빼냐? 할 수도 있다. 
        // 하지만 ? 6 1 4 인 경우 => 4 (공백) 3 2 1 인 반례가 존재한다.
        // a가 1일 때 max값이 맨 앞이기 때문에 하는 짓    
        int front = answer.getFirst();        
        answer.removeFirst();

        int sz = answer.size();
        for(int i=1; i<N-sz; ++i)
            answer.offerFirst(1);
            
        // 맨 앞 값 다시 끼워넣어주자.
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