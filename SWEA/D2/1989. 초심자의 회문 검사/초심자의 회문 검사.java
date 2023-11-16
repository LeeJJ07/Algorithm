import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		
		for(int test_case = 1;test_case<=n;test_case++) {
			String str = sc.nextLine();
			int i;
			for(i = 0;i<str.length()/2;i++) {
				if(str.charAt(i)!=str.charAt(str.length()-1-i))
					break;
			}
			if(i==str.length()/2) {
				System.out.printf("#%d %d\n",test_case,1);
			}else {
				System.out.printf("#%d %d\n",test_case,0);
			}
		}
	}
}