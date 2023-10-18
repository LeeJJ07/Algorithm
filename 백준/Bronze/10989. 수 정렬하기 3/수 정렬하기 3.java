import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
class Main{
	
	
	public static void main(String args[]) throws IOException{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(bf.readLine());
		int []num = new int[10001];
		for(int i = 0;i<N;i++) {
			num[Integer.parseInt(bf.readLine())]++;
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 1;i<=10000;i++) {
			for(int j = 0; j<num[i];j++) {
				sb.append(i+"\n");
			}
		}
		System.out.println(sb.toString());
	}
}