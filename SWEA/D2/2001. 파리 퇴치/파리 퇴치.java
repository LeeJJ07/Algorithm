
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)
		{
			int N = sc.nextInt();
			int M = sc.nextInt();
			int [][]map = new int[N][N];

			for(int i = 0;i<N;i++) {
				for(int j =0;j<N;j++) {
					map[i][j] = sc.nextInt();
				}
			}
			int start_i = 0, end_i = M;
			
			//처음 MXM 만큼의 더하기
			int sum1 = 0;
			for(int i = 0;i<M;i++) {
				for(int j = 0;j<M;j++) {
					sum1+=map[i][j];
				}
			}
			int result = sum1;
			while(true) {
				int start_j = 0, end_j = M;
				int sum2 = sum1;
				while(end_j<N) {
					for(int i = start_i;i<end_i;i++) {
						sum2+=map[i][end_j];
						sum2-=map[i][start_j];
					}
					if(result<sum2) {
						result = sum2;
					}
					start_j++;
					end_j++;
				}
                if(end_i>=N)
					break;
				
				for(int i = 0;i<M;i++) {
					sum1+=map[end_i][i];
					sum1-=map[start_i][i];
				}
				if(result<sum1)
					result = sum1;
				start_i++;
				end_i++;
				
			}
            System.out.printf("#%d %d\n",test_case,result);

		}
	}
}