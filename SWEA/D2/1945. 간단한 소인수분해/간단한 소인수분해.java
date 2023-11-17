import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int N = sc.nextInt();
			int[]count = new int[5];
			int[]num = {2,3,5,7,11};
			for(int i = 0;i<5;i++) {
				while(N%num[i]==0) {
					N/=num[i];
					count[i]++;
				}
			}
			System.out.printf("#%d ",test_case);
			for(int i = 0;i<5;i++) {
				System.out.print(count[i] + " ");
			}
			System.out.println();
		}
	}
}