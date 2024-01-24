import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.*;
public class Main{
	
	public static void main(String args[]) throws IOException{
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(bf.readLine());
		int N = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(bf.readLine());
		
		Deque<Node>de = new LinkedList<>();
		for(int i = 0 ;i<N;i++) {
			int cur = Integer.parseInt(st.nextToken());
			while(!de.isEmpty()&&de.getLast().value>cur) {
				de.removeLast();
			}
			de.addLast(new Node(cur,i));
			if(de.getFirst().index <= i-L)
				de.removeFirst();
			bw.write(de.getFirst().value + " ");
		}
		bw.flush();
		bw.close();
		
		
	}
	static class Node{
		public int value;
		public int index;
		
		Node(int value, int index){
			this.value = value;
			this.index = index;
		}
	}
}