
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
			long n = sc.nextLong();
            long result = 0;
            if(Math.sqrt(n) == (int)Math.sqrt(n)){
            	result =(long) (2 * (Math.sqrt(n)-1));
                System.out.printf("#%d %d\n",test_case, result);
                continue;
            }
            
            for(long i = (long)Math.sqrt(n); i>=1 ; i--){
            	if(n%i == 0){
                	result = i;
               		break;
                }
            }
            result = result-1 + n/result -1;
            System.out.printf("#%d %d\n",test_case,result);
        }
	}
}