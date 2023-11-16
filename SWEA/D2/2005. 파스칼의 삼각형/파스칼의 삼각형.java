import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int n = sc.nextInt();
			int [][]map = new int[n][n];
			for(int i = 0;i<n;i++) {
				map[i][0] = 1;
			}
			System.out.printf("#%d\n%d\n",test_case,map[0][0]);
			for(int i = 1;i<n;i++) {
				System.out.print(map[i][0]+" ");
				for(int j = 1;j<=i;j++) {
					map[i][j] = map[i-1][j-1]+map[i-1][j];
					System.out.print(map[i][j]+" ");
				}
				System.out.println();
			}
		}
	}
}
