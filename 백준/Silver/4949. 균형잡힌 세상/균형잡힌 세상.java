import java.util.*;
import java.io.*;

public class Main {
    static boolean getAnswer(String line) {

        Stack<Character> stk = new Stack<>();

        for(int i=0; i<line.length(); ++i) {

            char now = line.charAt(i);
            if(now == '(' || now == '[' || now == ')' || now == ']') {
                if (now == ')' || now == ']') {
                    if (stk.empty())
                        return false;

                    if ((now == ')' && stk.peek() != '(')
                            || (now == ']' && stk.peek() != '[')) {
                        return false;
                    }

                    stk.pop();
                    continue;
                }

                stk.push(now);
            }
        }
        
        return (stk.empty() ? true : false);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while(true) {
            String line = br.readLine();
            if(line.charAt(0) == '.') break;
            sb.append(getAnswer(line) ? "yes" : "no").append("\n");
        }
        System.out.print(sb.toString());
    }
}