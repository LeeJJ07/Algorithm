import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main
{
	static int []mx = {-1,0,1,0};
	static int []my = {0,1,0,-1};
	public static void dfs(int[][]map, int[][]check, int x, int y) {
		for(int i = 0;i<4;i++) {
			int nx = x+mx[i];
			int ny = y+my[i];
			if(nx<0||ny<0||nx>=map.length||ny>=map[0].length)
				continue;
			if(map[nx][ny]==0)
				continue;
			if(check[nx][ny]==1)
				continue;
			check[nx][ny]=1;
			dfs(map,check,nx,ny);
		}
	}
	
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int i = 0 ;i <T;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int M = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			
			int [][]map = new int[N][M];
			
			int num = Integer.parseInt(st.nextToken());
			for(int j = 0;j<num;j++) {
				st = new StringTokenizer(br.readLine());
				int y = Integer.parseInt(st.nextToken());
				int x = Integer.parseInt(st.nextToken());
				map[x][y] = 1;
			}
			int [][]check = new int[N][M];
			int result = 0;
			for(int p = 0;p<N;p++) {
				for(int q = 0;q<M;q++) {
					if(check[p][q] == 0 && map[p][q] == 1) {
						result++;
						check[p][q] = 1;
						dfs(map,check,p,q);
					}
				}
			}
			System.out.println(result);
		}
	}
}