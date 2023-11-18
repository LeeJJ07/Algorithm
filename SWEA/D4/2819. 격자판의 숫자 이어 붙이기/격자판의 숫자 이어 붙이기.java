import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int [][]map = new int[4][4];
			result = new HashSet<String>();
			for(int i = 0;i<4;i++) {
				for(int j = 0;j<4;j++) {
					map[i][j] = sc.nextInt();
				}
			}
			
			for(int i = 0;i<4;i++) {
				for(int j = 0;j<4;j++) {
					dfs(i,j,0,"",map);
				}
			}
			System.out.printf("#%d %d\n",test_case,result.size());
		}
	}
    static Set<String>result;
	
	static int[]mx = {1,0,-1,0};
	static int[]my = {0,-1,0,1};
	
	public static void dfs(int sx, int sy, int level,String str,
			int[][]map) {
		if(level == 7) {
			result.add(str);
			return;
		}
		for(int i = 0;i<4;i++) {
			int nx = sx+mx[i];
			int ny = sy+my[i];
			if(nx<0||ny<0||nx>=4||ny>=4)
				continue;
			dfs(nx,ny,level+1,str+map[nx][ny],map);
		}
	}
}