class Solution {
    public int solution(int n, int k) {
        int answer = 0;
        long num = 0;
        long z = 1;
        while(true){
            if(n%k==0){
                long i;
                for(i = 2;i<=Math.sqrt(num);i++){
                    if(num%i==0)
                        break;
                }
                if((num==2||(int)Math.sqrt(num)+1==i)&&num!=1)
                    answer++;
                num = 0;
                z = 1;
            }else{
                num+=(z*(n%k));
                z*=10;
            }
            if(n==0)
            	break;
            n/=k;
        }
        return answer;
    }
}