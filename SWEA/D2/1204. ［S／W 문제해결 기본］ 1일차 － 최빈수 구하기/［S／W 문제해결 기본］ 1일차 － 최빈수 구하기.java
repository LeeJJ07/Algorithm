import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int test_case = 0;test_case<T;test_case++) {
			int n = sc.nextInt();
			int []score = new int[101];
			for(int i = 0;i<1000;i++) {
				score[sc.nextInt()]++;
			}
			int max = -1;
			int maxidx = -1;
			for(int i = 0;i<101;i++) {
				if(max<=score[i]) {
					max = score[i];
					maxidx = i;
				}
			}
			System.out.printf("#%d %d\n",n, maxidx);
		}
	}
}