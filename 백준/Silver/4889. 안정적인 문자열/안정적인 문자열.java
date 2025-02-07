import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        for(int t=1; ; ++t) {
            String inp = br.readLine();

            if(inp.contains("-"))
                break;

            int answer = 0;
            Stack<Character> stk = new Stack<>();
            for(int i=0; i<inp.length(); ++i) {
                if(inp.charAt(i) == '{') {
                    stk.push('{');
                } else { 
                    if(stk.empty()) {
                        stk.push('{'); // 잘못된 짝이니 { 를 넣어 짝을 맞출 수 있음.
                        ++answer;
                    }
                    else if(stk.peek() == '{') {
                        stk.pop(); // 짝이 맞는 { 는 들어가지 않는다.
                    }
                }
            }

            char ch = 'x';
            while(!stk.empty()) {
                if(stk.pop() == '{') { // 잘못된 짝일 때만 넣어준 {
                    if(ch == '{') { // 방금 꺼낸게 {인데 또 {라는건.. 아까껄 수정하라는 뜻..
                        ch = 'x';
                        ++answer;
                    } else { 
                        ch = '{';
                    }
                }
            }


            sb.append(t).append(". ").append(answer).append("\n");
        }
        System.out.print(sb);

    } // main
}