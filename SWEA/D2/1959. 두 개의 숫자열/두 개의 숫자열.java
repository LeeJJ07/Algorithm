import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			
			int []A = new int[N];
			int []B = new int[M];
			
			for(int i = 0;i<N;i++) {
				A[i] = sc.nextInt();
			}
			for(int i = 0;i<M;i++) {
				B[i] = sc.nextInt();
			}
			int result = 0;
			if(A.length>=B.length) {
				for(int i = 0;i<=A.length-B.length;i++) {
					int sum = 0;
					for(int j = 0;j<B.length;j++) {
						sum+= A[i+j]*B[j];
					}
					if(sum>result)
						result = sum;
				}
			}else {
				for(int i = 0;i<=B.length-A.length;i++) {
					int sum = 0;
					for(int j = 0;j<A.length;j++) {
						sum+= A[j]*B[i+j];
					}
					if(sum>result)
						result = sum;
				}
			}
			System.out.printf("#%d %d\n",test_case, result);
		}
	}
}