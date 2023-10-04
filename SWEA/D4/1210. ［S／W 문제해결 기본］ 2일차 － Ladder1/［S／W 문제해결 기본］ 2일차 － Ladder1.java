
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T=10;

		for(int test_case = 1; test_case <= T; test_case++)
		{
			int n = sc.nextInt();
			int [][]map = new int[100][100];
			for(int i = 0;i<100;i++) {
				for(int j = 0;j<100;j++) {
					map[i][j] = sc.nextInt();
				}
			}
			boolean find = false;
			for(int j = 0;j<100;j++) {
				if(map[0][j]==1) {
					int ry = j;
					for(int i = 1;i<100;i++) {
						if(i==99) {
							if(map[i][ry]==2) {
								System.out.printf("#%d %d\n",test_case,j);
								find = true;
								break;
							}
						}
						if(ry!=99&&map[i][ry+1]==1) {
							ry++;
							while(true) {
								if(ry==99||map[i][ry+1]==0)
									break;
								ry+=1;
							}
						}
						else if(ry!=0&&map[i][ry-1]==1) {
							ry--;
							while(true) {
								if(ry==0||map[i][ry-1]==0)
									break;
								ry-=1;
							}
						}
					}
				}
				if(find) {
					break;
				}
			}
		}
	}
}