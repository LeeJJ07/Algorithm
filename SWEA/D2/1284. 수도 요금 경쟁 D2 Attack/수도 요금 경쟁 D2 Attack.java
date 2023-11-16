import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int test_case = 1;test_case<=T;test_case++) {
			int P = sc.nextInt(); //A사 1리터당 P원
			int Q = sc.nextInt();
			int R = sc.nextInt();
			int S = sc.nextInt();
			int W = sc.nextInt(); //한달간 사용하는 수도 양 W리터
			
			int A = W*P;
			int B = 0;
			if(W<=R)
				B = Q;
			else
				B = Q + (W-R) * S;
			
			System.out.printf("#%d %d\n",test_case,Math.min(A,B));
		}
	}
}