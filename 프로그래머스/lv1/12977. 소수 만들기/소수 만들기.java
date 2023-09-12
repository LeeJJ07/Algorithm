class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        for(int i = 0;i<nums.length-2;i++) {
        	for(int j = i+1;j<nums.length-1;j++) {
        		for(int k = j+1;k<nums.length;k++) {
        			int p;
        			if(Math.sqrt(nums[i]+nums[j]+nums[k])==(int)Math.sqrt(nums[i]+nums[j]+nums[k]))
        				continue;
        			for(p = 2;p<Math.sqrt(nums[i]+nums[j]+nums[k]);p++) {
        				if((nums[i]+nums[j]+nums[k])%p==0)
        					break;
        			}
        			if(p==(int)Math.sqrt(nums[i]+nums[j]+nums[k])+1) {
        				answer++;
        			}
        			
        		}
        	}
        }

        return answer;
    }
}