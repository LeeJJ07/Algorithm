class Solution {
    public int[] solution(int brown, int yellow) {
        
        int a = brown/2 + 2;
        int n = (int)(a+Math.sqrt((a*a - 4*(2*a+yellow-4))))/2;
        int m = (int)(a-Math.sqrt(a*a - 4*(2*a+yellow-4)))/2;
        int[] answer = {n,m};
        return answer;
    }
}