import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int n = sc.nextInt();
			int start = 0;
			int result = 0;
			for(int i = 0;i<n;i++) {
				int k = sc.nextInt();
				if(k==1) {
					int m = sc.nextInt();
					start+=m;
				}else if(k==2){
					int m = sc.nextInt();
					start-=m;
					if(start<0)
						start = 0;
				}
				result+=start;
			}
			
			System.out.printf("#%d %d\n",test_case,result);
		}
	}
}