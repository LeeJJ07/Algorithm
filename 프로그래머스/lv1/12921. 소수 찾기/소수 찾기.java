class Solution {
    public int solution(int n) {
        int answer = 0;
        if(n==2)
            return 1;
        for(int i = 2;i<=n;i++){
            int j;
            for(j = 2;j<Math.sqrt(i);j++){
                if((int)Math.sqrt(i)==Math.sqrt(i)){
                    break;
                }
                if(i%j==0)
                    break;
            }
            if(j==(int)Math.sqrt(i)+1)
                answer++;
        }
        return answer;
    }
}