class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int [][]map = new int[n+1][m+1];
        for(int i = 0;i<puddles.length;i++){
            map[puddles[i][1]-1][puddles[i][0]-1] = -1;
        }
        map[n-1][m-1]=1;
        for(int j = m-1;j>=0;j--){
            for(int i = n-1;i>=0;i--){
                if(j==m-1 && i==n-1)
                    continue;
                if(map[i][j]==-1)
                    continue;
                if(map[i+1][j]==-1&&map[i][j+1]==-1){
                    map[i][j]=0;
                }else if(map[i][j+1]==-1){
                    map[i][j] = map[i+1][j];
                }else if(map[i+1][j]==-1){
                    map[i][j] = map[i][j+1];
                }else{
                    map[i][j] = map[i][j+1]+map[i+1][j];
                }
                map[i][j]%=1000000007;
            }
        } 
        
        return map[0][0];
    }
}