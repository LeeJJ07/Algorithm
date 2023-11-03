
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		
        int []months = {31,28,31,30,31,30,31,31,30,31,30,31};

		for(int test_case = 1; test_case <= T; test_case++)
		{
			int num = sc.nextInt();
            int year = num/10000;
            int month = (num%10000)/100;
            int day = num%100;
            if(month<=0 || month>12||months[month-1]<day||day<=0){
            	System.out.println("#"+test_case + " -1");
            }else{
            	System.out.printf("#%d %04d/%02d/%02d\n",test_case,year,month,day);
            }
		}
	}
}