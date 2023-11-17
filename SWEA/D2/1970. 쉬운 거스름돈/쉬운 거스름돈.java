import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int []money = {50000,10000,5000,1000,500,100,50,10};

		for (int test_case = 1; test_case <= T; test_case++) {
			int m = sc.nextInt();
			int []count = new int[8];
			int idx = 0;
			while(idx<8&&m>0) {
				count[idx] = m/money[idx];
				m %= money[idx];
				idx++;
			}
			System.out.println("#" + test_case);
			for(int i = 0;i<8;i++) {
				System.out.print(count[i]+" ");
			}
			System.out.println();
		}
	}
}