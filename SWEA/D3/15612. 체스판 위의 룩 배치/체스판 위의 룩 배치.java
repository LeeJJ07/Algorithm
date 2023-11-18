import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int [][]map = new int[8][8];
			for(int i = 0;i<8;i++) {
				String str = sc.next();
				for(int j = 0;j<8;j++) {
					if(str.charAt(j) == 'O') {
						map[i][j] = 1;
					}
				}
			}
			boolean okay = true;
			int []check = new int[8];
			for(int i = 0;i<8;i++) {
				boolean chk = false;
				for(int j = 0;j<8;j++) {
					if(map[i][j]==1) {
						if(check[j]==1) {
							okay = false;
							break;
						}
						if(chk==true) {
							okay = false;
							break;
						}
						check[j] = 1;
						chk = true;
					}
				}
				if(!chk)
					okay = false;
				if(!okay)
					break;
			}
			if(okay) {
				System.out.println("#"+test_case+ " yes");
			}else {
				System.out.println("#"+test_case+ " no");
			}
		}
	}
}