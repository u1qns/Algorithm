import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

	static int N, M, answer = 0;
	static Integer[] tree; // sort 쓰려고 int 에서 타입 변경

	static long solve_loop()
	{		
	    long mid = 0;
	    long max = tree[0];
	    long min = 0;
	    
	    while(min <= max)
	    {
	        long sum = 0;
	        for(int t : tree)
	        {
	        	if(t < mid) break;
	                sum += t-mid;
	        }
	
	        if(sum >= M)
	            min = mid + 1;
	        else
	            max = mid - 1;
	        
	        mid = (max+min)/2;
	    }
	    
	    return mid;
	}
	
	public static void main(String[] args) throws IOException {

		//StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		tree = new Integer[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; ++i)
			tree[i] = Integer.parseInt(st.nextToken());

		Arrays.sort(tree, Collections.reverseOrder());
		
		long answer = solve_loop();
		System.out.print(answer);
	} // main
}