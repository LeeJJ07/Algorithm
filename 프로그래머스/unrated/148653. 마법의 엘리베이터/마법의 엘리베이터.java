class Solution {
    public int solution(int storey) {
        int answer1 = 0;
        int storey1 = storey;
        while(storey>0){
            if(storey%10>5){
                answer1+=(10 - storey%10);
                storey/=10;
                storey++;
            }else{
                answer1+=(storey%10);
                storey/=10;
            }
        }
        int answer2 = 0;
        while(storey1>0){
            if(storey1%10>=5){
                answer2+=(10 - storey1%10);
                storey1/=10;
                storey1++;
            }else{
                answer2+=(storey1%10);
                storey1/=10;
            }
        }
        
        return answer1>answer2?answer2:answer1;
    }
}