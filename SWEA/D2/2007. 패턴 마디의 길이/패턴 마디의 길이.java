
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();
		
		for(int test_case = 1;test_case<=T;test_case++) {
			String str = sc.nextLine();
			int i;
			for(i = 1;i<30;i++) {
				if(str.charAt(0)!=str.charAt(i))
					continue;
				int j;
				for(j = 0;j<i;j++) {
					if(str.charAt(j)!=str.charAt(i+j)) {
						break;
					}
				}
				if(j==i)
					break;
			}
			System.out.printf("#%d %d\n",test_case, i);
		}
	}
}