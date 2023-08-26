class Solution {
    static void dfs(int[][]com,int[]check,int s,int n){
        for(int i = 0;i<n;i++){
            if(check[i]!=0)
                continue;
            if(com[s][i]==0)
                continue;
            check[i] = 1;
            dfs(com,check,i,n);
        }
    }
    public int solution(int n, int[][] computers) {
        int answer = 0;
        int []check = new int[n];
        for(int i = 0;i<n;i++){
            if(check[i]!=0)
                continue;
            answer++;
            check[i] = 1;
            dfs(computers, check, i, n);
        }
        return answer;
    }
}