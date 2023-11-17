import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int[][] sdq = new int[9][9];
			boolean result = true;

			for (int i = 0; i < 9; i++) {
				int[] check = new int[9];
				for (int j = 0; j < 9; j++) {
					sdq[i][j] = sc.nextInt();
					if (check[sdq[i][j] - 1] == 1) {
						result = false;
					}
					check[sdq[i][j] - 1] = 1;
				}
			}
			if (!result) {
				System.out.printf("#%d 0\n", test_case);
				continue;
			}

			for (int i = 0; i < 9; i++) {
				int[] check = new int[9];
				for (int j = 0; j < 9; j++) {
					if (check[sdq[j][i] - 1] == 1) {
						result = false;
						break;
					}
					check[sdq[j][i] - 1] = 1;
				}
				if (!result)
					break;
			}
			if (!result) {
				System.out.printf("#%d 0\n", test_case);
				continue;
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int[] check = new int[9];
					for (int p = 0; p < 3; p++) {
						for (int q = 0; q < 3; q++) {
							if (check[sdq[3 * i + p][3 * j + q] - 1] == 1) {
								result = false;
								break;
							}
							check[sdq[3 * i + p][3 * j + q] - 1] = 1;
						}
						if (!result)
							break;
					}
					if (!result)
						break;
				}
				if (!result)
					break;
			}
			if (!result) {
				System.out.printf("#%d 0\n", test_case);
				continue;
			}
			System.out.printf("#%d 1\n", test_case);
		}
	}
}