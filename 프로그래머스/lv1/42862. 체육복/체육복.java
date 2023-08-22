class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        int []person = new int[n];
        for(int i = 0;i<lost.length;i++){
            person[lost[i]-1]--;
        }
        for(int i = 0;i<reserve.length;i++){
            person[reserve[i]-1]++;
        }
        for(int i = 0;i<n;i++){
            if(person[i]==-1){
                if(i-1>=0 && person[i-1]==1){
                    person[i-1] = 0;
                    person[i] = 0;
                    continue;
                }
                if(i+1<n&&person[i+1]==1){
                    person[i+1] = 0;
                    person[i]= 0;
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(person[i]>=0)
                answer++;
        }
        return answer;
    }
}