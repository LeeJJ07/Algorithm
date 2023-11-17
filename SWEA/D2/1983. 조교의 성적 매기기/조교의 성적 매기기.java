import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		String[]score = {"A+", "A0", "A-", "B+", "B0", "B-","C+", "C0", "C-","D0"};
		
		for(int test_case = 1;test_case<=T;test_case++) {
			int n = sc.nextInt();
			int id = sc.nextInt()-1;
			double []sum = new double[n];
			for(int i = 0 ;i<n;i++) {
				sum[i] += sc.nextInt() * 35 + sc.nextInt() * 45 + sc.nextInt()*20;
				sum[i] /= 100;
			}
			int count = 0;
			for(int i = 0 ;i<n;i++) {
				if(i==id)
					continue;
				if(sum[i]>sum[id])
					count++;
			}
			System.out.printf("#%d %s\n",test_case, score[count / (n/10)]);
			
		}
	}
}