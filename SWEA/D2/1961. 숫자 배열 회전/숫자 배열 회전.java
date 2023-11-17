import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int N = sc.nextInt();
			int [][]map = new int[N][N];
			for(int i =  0;i<N;i++) {
				for(int j = 0;j<N;j++) {
					map[i][j] = sc.nextInt();
				}
			}
			int [][]map90 = new int[N][N];
			int [][]map180 = new int[N][N];
			int [][]map270 = new int[N][N];
			
			for(int i = 0;i<N;i++) {
				for(int j = 0;j<N;j++) {
					map90[i][j] = map[N-1-j][i];
				}
			}
			
			for(int i = 0;i<N;i++) {
				for(int j = 0;j<N;j++) {
					map180[i][j] = map[N-1-i][N-1-j];
				}
			}
			
			for(int i = 0;i<N;i++) {
				for(int j = 0;j<N;j++) {
					map270[i][j] = map[j][N-1-i];
				}
			}
			System.out.println("#"+test_case);
			for(int i = 0;i<N;i++) {
				for(int j = 0;j<N;j++) {
					System.out.print(map90[i][j]);
				}
				System.out.print(" ");
				for(int j = 0;j<N;j++) {
					System.out.print(map180[i][j]);
				}
				System.out.print(" ");
				for(int j = 0;j<N;j++) {
					System.out.print(map270[i][j]);
				}
				System.out.println();
			}
		}
	}
}