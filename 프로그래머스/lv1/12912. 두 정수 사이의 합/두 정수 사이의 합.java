class Solution {
    public long solution(int a, int b) {
        long answer = (Math.abs(b-a)+1)*((long)a+b)/2;
        return answer;
    }
}