import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		str = str.toUpperCase();
		
		for(int i = 0;i<str.length();i++) {
			System.out.print((str.charAt(i)-'A'+1) + " ");
		}
	}
}