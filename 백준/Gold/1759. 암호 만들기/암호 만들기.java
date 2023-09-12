import java.util.*;
import java.io.BufferedReader;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static ArrayList<String>result;
	
	static void dfs(int L, int K, int sidx, int count1, int count2, String[]c, int level,StringBuilder sb ) {
		
		if(level==L) {
			if(count1>=1&&count2>=2)
				result.add(sb.toString());
			return;
		}
		
		for(int i = sidx+1;i<K;i++) {
			if(c[i].equals("a")||c[i].equals("e")||c[i].equals("i")||c[i].equals("o")||c[i].equals("u")) {
				sb.append(c[i]);
				dfs(L,K,i,count1+1,count2,c,level+1,sb);
				sb.deleteCharAt(sb.length()-1);
			}else {
				sb.append(c[i]);
				dfs(L,K,i,count1,count2+1,c,level+1,sb);
				sb.deleteCharAt(sb.length()-1);
			}
			
		}
	}
    
    public static void main(String args[]) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	int L = Integer.parseInt(st.nextToken());
    	int K = Integer.parseInt(st.nextToken());
    	
    	st = new StringTokenizer(br.readLine());
    	String []c = new String[K];
    	for(int i = 0;i<K;i++) {
    		c[i] = st.nextToken();
    	}
    	Arrays.sort(c);
    	result = new ArrayList<String>();
    	StringBuilder sb = new StringBuilder();
    	dfs(L,K,-1,0,0,c,0,sb);
    	
    	Collections.sort(result);
    	for(int i = 0;i<result.size();i++) {
    		System.out.println(result.get(i));
    	}
    	
    }
}