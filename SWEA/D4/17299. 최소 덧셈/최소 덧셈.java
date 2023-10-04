
import java.util.Scanner;
import java.io.FileInputStream;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		sc.nextLine();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			String str = sc.nextLine();
			int sum = 0;
			if(str.length()%2==0) {
				sum = Integer.parseInt(str.substring(0,str.length()/2))
						+Integer.parseInt(str.substring(str.length()/2));
			}else {
				if(str.charAt(0)<str.charAt(str.length()/2)) {
					sum = Integer.parseInt(str.substring(0,str.length()/2+1))
							+Integer.parseInt(str.substring(str.length()/2+1));
				}else {
					sum = Integer.parseInt(str.substring(0,str.length()/2))
							+Integer.parseInt(str.substring(str.length()/2));
				}
			}
			System.out.printf("#%d %d\n",test_case,sum);
		}
	}
}