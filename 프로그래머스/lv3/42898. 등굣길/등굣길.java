class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int [][]map = new int[n][m];
        for(int i = 0;i<puddles.length;i++){
            map[puddles[i][1]-1][puddles[i][0]-1] = -1;
        }
        int num = 1;
        for(int i = n-1;i>=0;i--){
            if(map[i][m-1]==-1){
                num = 1;
                break;
            }
            map[i][m-1] = num;
        }
        for(int j = m-1;j>=0;j--){
            if(map[n-1][j]==-1){
                break;
            }
            map[n-1][j] = num;
        }
        for(int j = m-2;j>=0;j--){
            for(int i = n-2;i>=0;i--){
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