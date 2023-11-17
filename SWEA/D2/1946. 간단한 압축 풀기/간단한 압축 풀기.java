import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int N = sc.nextInt();
			int count = 0;
			System.out.println("#"+test_case);
			for(int i = 0;i<N;i++) {
				String str = sc.next();
				int num = sc.nextInt();
				for(int j = 0;j<num;j++) {
					System.out.print(str);
					count++;
					if(count==10) {
						System.out.println();
						count = 0;
					}
				}
			}
			System.out.println();
		}
	}
}