class Solution {
    static int answer = 0;
    static void dfs(int n, String[]data, int[]check,int level,
                   char[]name,char[]realname){
        for(int i = 0;i<n;i++){
            int d = data[i].charAt(4)-'0';
            char a = data[i].charAt(0);
            char b = data[i].charAt(2);
            char c = data[i].charAt(3);
            int s = -1; int e = -1;
            for(int j = 0;j<=level;j++){
                if(name[j]==a)
                    s = j;
                else if(name[j]==b)
                    e = j;
            }
            if(s==-1||e==-1)
                continue;
            if(c=='='){
                if(Math.abs(s-e)-1!=d){
                    return;
                }
            }else if(c=='>'){
                if(Math.abs(s-e)-1<=d){
                    return;
                }
            }else{
                if(Math.abs(s-e)-1>=d){
                    return;
                }
            }
        }
        
        if(level==7){
            answer++;
            return;
        }
        
        for(int i = 0;i<8;i++){
            if(check[i]==1)
                continue;
            check[i] = 1;
            name[level+1] = realname[i];
            dfs(n,data,check,level+1,name,realname);
            check[i] = 0;
        }
        
    }
    public int solution(int n, String[] data) {
        int []check = new int[8];
        char []name = new char[8];
        char []realname = {'A','C','F','J','M','N','R','T'};
        //A = 0, C = 1, F = 2, J = 3, M = 4, N = 5, R = 6, T = 7;
        answer= 0;
        for(int i = 0;i<8;i++){
            check[i] = 1;
            name[0] = realname[i];
            dfs(n,data,check,0,name, realname);
            check[i] = 0;
        }
        return answer;
    }
}