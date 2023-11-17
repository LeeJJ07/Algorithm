import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int N = sc.nextInt();
			int []num = new int[N];
			for(int i = 0;i<N;i++) {
				num[i] =sc.nextInt();
			}
			Arrays.sort(num);
			System.out.print("#"+test_case+" ");
			for(int i = 0;i<N;i++)
				System.out.print(num[i] + " ");
			System.out.println();
		}
	}
}
