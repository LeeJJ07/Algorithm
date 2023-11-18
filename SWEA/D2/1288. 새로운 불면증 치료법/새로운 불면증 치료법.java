import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int n = sc.nextInt();
			int count = 0;
			int result = 0;
			Set<Integer>set = new HashSet<Integer>();
			while(set.size()!=10) {
				count++;
				int num = n*count;
				while(num>0) {
					set.add(num%10);
					num/=10;
				}
	
			}
			System.out.printf("#%d %d\n",test_case, n*count);
		}
	}
}
