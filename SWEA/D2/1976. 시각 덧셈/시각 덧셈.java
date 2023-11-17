import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int bh = sc.nextInt();
			int bm = sc.nextInt();
			int sh = sc.nextInt();
			int sm = sc.nextInt();
			
			int after = (bh+sh) * 60 + (bm+sm);
			if(after>=780) {
				after-=720;
			}
			
			System.out.printf("#%d %d %d\n",test_case,after/60,after%60);
		}
	}
}
