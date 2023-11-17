import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int n = sc.nextInt();
			int K = sc.nextInt();
			int result = 0;
			int[][] map = new int[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int count = 0;
					while (j<n && map[i][j] == 1 ) {
						j++;
						count++;
					}
					if(count == K) {
						result++;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int count = 0;
					while (j<n && map[j][i] == 1) {
						j++;
						count++;
					}
					if(count == K) {
						result++;
					}
				}
			}
			System.out.printf("#%d %d\n",test_case,result);
		}
	}
}