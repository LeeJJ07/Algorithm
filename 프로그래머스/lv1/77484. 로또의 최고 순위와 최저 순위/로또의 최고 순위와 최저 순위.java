import java.util.Set;
import java.util.HashSet;
class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int count = 0;
        int zeroCount = 0;
        Set<Integer>set = new HashSet<Integer>();
        for(int i = 0;i<win_nums.length;i++)
        	set.add(win_nums[i]);
        for(int i = 0;i<lottos.length;i++) {
        	if(lottos[i]==0)
        		zeroCount++;
        	else if(set.contains(lottos[i]))
        		count++;
        }
        int best = 7-count-zeroCount;
        int worst = 7-count;
        if(best<1) best = 1;
        if(best>6) best = 6;
        if(worst>6) worst = 6;
        int[] answer = {best,worst};
        
        return answer;
    }
}