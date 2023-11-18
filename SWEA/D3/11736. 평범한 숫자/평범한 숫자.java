import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int n = sc.nextInt();
			int []num = new int[n];
			for(int i = 0;i<n;i++)
				num[i] = sc.nextInt();
			int result = 0;
			for(int i = 1;i<n-1;i++) {
				if(num[i]==Math.max(Math.max(num[i], num[i-1]), num[i+1])) {
					continue;
				}
				if(num[i]==Math.min(Math.min(num[i], num[i-1]), num[i+1])) {
					continue;
				}
				result++;
			}
			System.out.printf("#%d %d\n",test_case, result);
		}
	}
}