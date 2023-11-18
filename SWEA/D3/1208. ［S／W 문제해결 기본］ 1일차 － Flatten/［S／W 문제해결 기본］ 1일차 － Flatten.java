import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = 10;

		for (int test_case = 1; test_case <= T; test_case++) {
			int n = sc.nextInt();
			int [][]check = new int[100][100];
			for(int i = 0;i<100;i++) {
				int height = sc.nextInt();
				for(int j = 0;j<height;j++) {
					check[100-j-1][i] = 1;
				}
			}
			
			int upi = 0;
			int upj = 0;
			int downi = 99;
			int downj = 0;
			while(n>=0 && upi<=downi) {
				while(check[upi][upj]!=1) {
					upj++;
					if(upj==100) {
						upj=0;
						upi++;
					}
				}
				while(check[downi][downj]!=0) {
					downj++;
					if(downj==100) {
						downj=0;
						downi--;
					}
				}
				check[upi][upj]=0;
				check[downi][downj] = 1;
				n--;
			}
			System.out.printf("#%d %d\n",test_case,Math.abs(upi-downi)+1);
		}
	}
}