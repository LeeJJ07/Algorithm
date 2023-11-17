import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int test_case = 1;test_case<=T;test_case++) {
			int []num = new int[10];
			for(int i = 0;i<10;i++) {
				num[i] = sc.nextInt();
			}
			Arrays.sort(num);
			double sum = 0;
			for(int i = 1;i<9;i++) {
				sum+=num[i];
			}
			System.out.printf("#%d %d\n", test_case, (int)Math.round(sum/8));
		}
	}
}