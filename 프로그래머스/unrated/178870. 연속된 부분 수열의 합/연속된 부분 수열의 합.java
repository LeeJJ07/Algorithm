class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = new int[2];
        int min = 1000001;
        int start = 0;
        int end = 0;
        int sum = sequence[start];
        while(start<=end){
            if(sum<k){
                end++;
                if(end>=sequence.length)
                    break;
                sum+=sequence[end];
            }else if(sum>k){
                sum-=sequence[start];
                start++;
            }else if(sum==k){
                if(end-start<min){
                    min = end-start;
                    answer[0] = start;
                    answer[1] = end;
                }
                end++;
                if(end>=sequence.length)
                    break;
                sum+=sequence[end];
                sum-=sequence[start];
                start++;
            }
        }
        return answer;
    }
}