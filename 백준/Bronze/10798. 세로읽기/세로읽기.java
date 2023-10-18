import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
class Main{
	
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String []map = new String[5];
		int maxlen = 0;
		for(int i = 0;i<5;i++) {
			StringTokenizer st  = new StringTokenizer(br.readLine());
			map[i] = st.nextToken();
			if(map[i].length()>maxlen)
				maxlen = map[i].length();
		}
		for(int j = 0;j<maxlen;j++) {
			for(int i = 0;i<5;i++) {
				if(map[i].length()<=j)
					continue;
				System.out.print(map[i].charAt(j));
			}
		}
	}
}