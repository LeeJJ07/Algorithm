
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
			int n = sc.nextInt();
			int[]num = new int[n];
			for(int i = 0;i<n;i++) {
				num[i] = sc.nextInt();
			}
			long sum = 0;
			for(int i = 0;i<n-1;i++) {
				int max = num[i];
				int maxidx = i;
				for(int j = i+1;j<n;j++) {
					if(max<num[j]) {
						maxidx = j;
						max = num[j];
					}
				}
				if(maxidx != i) {
					for(int j = i;j<maxidx;j++) {
						sum +=(max - num[j]);
					}
					i = maxidx;
				}
			}
			System.out.printf("#%d %d\n",test_case,sum);
		}
	}
}