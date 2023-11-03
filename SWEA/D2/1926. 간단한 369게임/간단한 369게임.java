
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int i = 1; i <= T; i++)
		{
			String[]num = String.valueOf(i).split("");
			int count = 0;
			for(int j = 0;j<num.length;j++) {
				if(num[j].equals("3")||num[j].equals("6")||num[j].equals("9"))
					count++;
			}
			
			if(count==0) {
				System.out.print(i + " ");
			}else {
				for(int j = 0;j<count;j++) {
					System.out.print("-");
				}
				System.out.print(" ");
			}
		}
	}
}