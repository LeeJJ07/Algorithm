import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int []month = {31,28,31,30,31,30,31,31,30,31,30,31};

		for (int test_case = 1; test_case <= T; test_case++) {
			int fmonth = sc.nextInt();
			int fday = sc.nextInt();
			int smonth = sc.nextInt();
			int sday = sc.nextInt();
			
			int day = 0;
			for(int i = fmonth; i<smonth;i++) {
				day += month[i-1];
			}
			day += sday-fday+1;
			System.out.printf("#%d %d\n",test_case, day);
		}
	}
}
