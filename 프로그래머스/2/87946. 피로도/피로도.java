class Solution {
    static int max = 0;
	static void dfs(int k, int []check, int[][]dungeons, int level) {
		if(level==dungeons.length) {
			max = level;
			return;
		}
		if(level>max)
			max = level;
		for(int i = 0;i<dungeons.length;i++) {
			if(check[i]==1)
				continue;
			if(k>=dungeons[i][0]) {
				check[i] = 1;
				
				dfs(k-dungeons[i][1],check,dungeons,level+1);
				check[i] = 0;
			}
		}
	}
    public int solution(int k, int[][] dungeons) {
        max = 0;
        int []check = new int[dungeons.length];
        dfs(k,check,dungeons,0);
        
        return max;
    }
}