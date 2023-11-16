import java.util.Scanner;
import java.io.FileInputStream;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 0;i<=n;i++)
			System.out.print((int)Math.pow(2, i) + " ");
	}
}