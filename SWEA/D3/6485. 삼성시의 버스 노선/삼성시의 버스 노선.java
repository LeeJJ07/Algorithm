
import java.io.*;
import java.util.*;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(bufferedReader.readLine());
        StringTokenizer st;

		for (int test_case = 1; test_case <= T; test_case++) {
			int N = Integer.parseInt(bufferedReader.readLine());
            int[]arr = new int[5001];
				for(int i = 0 ; i < N ; i++) {
               		st = new StringTokenizer(bufferedReader.readLine());
                	int a = Integer.parseInt(st.nextToken());
                	int b = Integer.parseInt(st.nextToken());
                	for(int j = a ; j <= b ; j++) {
                    	arr[j]++;
                	}   
            	
			}
			System.out.print("#" + test_case);
            int p = Integer.parseInt(bufferedReader.readLine());
            for(int i = 0 ; i < p ; i++) {
                int c = Integer.parseInt(bufferedReader.readLine());
                System.out.print(" " + arr[c]);
            }
            System.out.println();
			
		}
	}
}