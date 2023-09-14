class Solution {
    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        for(int i = Math.min(n,m);i>=1;i--){
            if(n%i==0&&m%i==0){
                answer[0] = i;
                break;
            }
        }
        int max = Math.max(n,m);
        for(long i = max;i>0;i+=max){
            if(i%n==0&&i%m==0){
                answer[1] = (int)i;
                break;
            }
        }
        return answer;
    }
}