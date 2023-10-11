import java.util.Queue;
import java.util.PriorityQueue;
class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        Queue<Integer>q = new PriorityQueue<Integer>();
        for(int i = 0;i<scoville.length;i++) {
        	q.add(scoville[i]);
        }
        
        while(q.peek()<K) {
            if(q.size()<2)
        		return -1;
        	int num1 = q.poll();
        	int num2 = q.poll();
        	q.add(num1+num2*2);
        	answer++;
        }
        return answer;
    }
}