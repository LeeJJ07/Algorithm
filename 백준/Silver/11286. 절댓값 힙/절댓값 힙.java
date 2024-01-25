import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main{
	
	public static void main(String args[]) throws IOException{
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(bf.readLine());
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>((o1,o2)->{
			int a = Math.abs(o1);
			int b = Math.abs(o2);
			if(a==b) {
				return o1>o2 ? 1 : -1;
			}
			else {
				return a-b;
			}
		});
		for(int i = 0;i<N;i++) {
			int request = Integer.parseInt(bf.readLine());
			if(request==0) {
				if(pq.isEmpty())
					System.out.println("0");
				else
					System.out.println(pq.poll());
			}
			else {
				pq.add(request);
			}
		}
	}
}