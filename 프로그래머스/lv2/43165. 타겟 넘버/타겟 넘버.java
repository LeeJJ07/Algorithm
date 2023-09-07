class Solution {
    static int answer = 0;
    static void dfsPlus(int[]numbers,int idx, int target,int sum){
    	sum += numbers[idx];
        if(idx==numbers.length-1){
            if(target == sum)
                answer++;
            return;
        }
        dfsPlus(numbers,idx+1,target,sum);
        dfsMinus(numbers,idx+1,target,sum);
    }
    static void dfsMinus(int[]numbers,int idx, int target,int sum){
    	sum -= numbers[idx];
        if(idx==numbers.length-1){
            if(target == sum)
                answer++;
            return;
        }
        
        dfsPlus(numbers,idx+1,target,sum);
        dfsMinus(numbers,idx+1,target,sum);
        
    }
    
    public int solution(int[] numbers, int target) {
        answer = 0;
        dfsPlus(numbers,0,target,0);
        dfsMinus(numbers,0,target,0);
        return answer;
    }
}