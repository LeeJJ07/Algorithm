class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;
        for(int i = 0;i<=r2;i++){
            double num1 = Math.sqrt((long)r1*r1-(long)i*i);
            double num2 = (long)Math.sqrt((long)r1*r1-(long)i*i);
            double num3 = Math.sqrt((long)r2*r2-(long)i*i);
            double num4 = (long)Math.sqrt((long)r2*r2-(long)i*i);
            if(i<=r1){
                answer+=(num4-num2);
                if(num1==num2){
                    answer++;
                }
            }
            else{
                answer+=(num4+1);
            }
        }
        answer-=(r2-r1+1);
        return 4*answer;
    }
}