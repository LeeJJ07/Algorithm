class Solution {
    public int solution(int num) {
        int answer = 0;
        long number = num;
        while(number!=1&&answer<500){
            number = (number%2==0)?(number/2):(number*3+1);
            answer++;
        }
        if(answer==500)
            return -1;
        return answer;
    }
}