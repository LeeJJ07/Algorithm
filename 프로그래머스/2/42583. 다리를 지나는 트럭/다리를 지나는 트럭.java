import java.util.*;
class Solution {
    static class Node{
		int weight;
		int Time;
		Node(int weight, int t){
			this.weight = weight;
			this.Time = t;
		}
	}
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int time = 0;
        int curWeight = 0;
        Deque<Node> q = new LinkedList<Node>();
        int idx = 0;
        while(true) {
        	if(idx>=truck_weights.length)
        		break;
        	if(q.size()!=0 && q.getFirst().Time+bridge_length<=time) {
        		curWeight -=q.getFirst().weight;
        		q.removeFirst();
        	}
        	
        	if(curWeight + truck_weights[idx] > weight) {
        		time += (bridge_length + q.getFirst().Time - time -1);
        		curWeight -= q.getFirst().weight;
        		q.removeFirst();
        	}else {
        		time++;
        		q.addLast(new Node(truck_weights[idx], time));
        		curWeight+=truck_weights[idx];
        		idx++;
        	}
        }
        if(!q.isEmpty()) {
        	time += (bridge_length + q.getLast().Time - time);
        }
        
        return time;
    }
}