import java.io.*;
import java.util.*;

public class Main {
    static int N, K;
    // 손님은 그냥 시간빠른 순
    static PriorityQueue<Node> out = new PriorityQueue<>(new Comparator<Node>() {
        @Override
        public int compare(Node p1, Node p2) {
            if (p1.time == p2.time)
                return Integer.compare(p2.idx, p1.idx);
            return Integer.compare(p1.time, p2.time);
        }
    });

    static long solve(List<Node> customers) {
        
        long answer = 0L;
        int cnt = 1;
        
        PriorityQueue<Node> cashiers = new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node p1, Node p2) {
                if (p1.time == p2.time)
                    return Integer.compare(p1.idx, p2.idx);
                return Integer.compare(p1.time, p2.time);
            }
        });

        for(int i=1; i<=K; ++i) {
            cashiers.offer(new Node(i, 0, -1));
        }

        // out한대로 모아놓을까? 나간 시간, 캐셔, 고객 아이디 일케 모아놧다가 일괄 처리해도 될듯 
        for(int i=0; i<N; ++i) {
            Node customer = customers.get(i);
            Node cashier = cashiers.poll();

            if(cashier.num != -1)
                out.offer(cashier); // 캐셔가 가지고 있던 손님 아웃임

            // 다음 손님 받음
            cashiers.offer(new Node(cashier.idx, cashier.time + customer.time, customer.idx));
        }

        // 캐셔에 혹시 남아있을 까봐 
        while(!cashiers.isEmpty()) {
            Node cashier = cashiers.poll();
            if(cashier.num != -1)
                out.offer(cashier);
        }

        while(!out.isEmpty()) {
            answer += ((long)out.poll().num * cnt++);
        }
        return answer;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        List<Node> customers = new ArrayList<>();
        for(int i=0; i<N; ++i) {
            st = new StringTokenizer(br.readLine());
            int idx = Integer.parseInt(st.nextToken());
            int time = Integer.parseInt(st.nextToken());
            customers.add(new Node(idx, time));
        }
        
        System.out.print(solve(customers));
    
    } // main

    static class Node {

        Node(int idx, int time, int num) {
            this.idx = idx;
            this.time = time;
            this.num = num;
        }

        
        Node(int idx, int time) {
            this.idx = idx;
            this.time = time;
            this.num = 0;
        }

        int idx;
        int time;
        int num;

    }
}