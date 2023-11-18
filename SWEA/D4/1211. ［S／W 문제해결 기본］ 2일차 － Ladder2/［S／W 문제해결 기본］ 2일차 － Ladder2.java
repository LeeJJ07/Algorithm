import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = 10;

		for (int test_case = 1; test_case <= T; test_case++) {
			int n = sc.nextInt();
			int [][]map = new int[100][100];
			for(int i = 0;i<100;i++) {
				for(int j = 0;j<100;j++) {
					map[i][j] = sc.nextInt();
				}
			}
			int min = 10000;
			int minidx = -1;
			for(int j = 0;j<100;j++) {
				if(map[0][j]==1) {
					int count = 0;
					int i = 0;
					int stj = j;
					while(i<100) {
						if(stj+1<100 && map[i][stj+1]==1) {
							while(stj+1<100&&map[i][stj+1]!=0) {
								stj++;
								count++;
							}
							i++;
						}else if(stj -1 >= 0 && map[i][stj-1]==1) {
							while(stj-1>=0&&map[i][stj-1]!=0) {
								stj--;
								count++;
							}
							i++;
						}else {
							i++;
						}
					}
					if(min>count) {
						min = count;
						minidx = j;
					}
				}
			}
			System.out.printf("#%d %d\n",test_case,minidx);
		}
	}
}