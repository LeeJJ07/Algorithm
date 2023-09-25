import java.util.*;
class Solution {
    static class Node implements Comparable<Node>{
        int idx;
        int value;
        Node(int idx, int value){
            this.idx = idx;
            this.value = value;
        }
		@Override
		public int compareTo(Node o) {
			// TODO Auto-generated method stub
			if(this.value<o.value)
				return 1;
			else
				return -1;
		}
    }
    public int solution(int n, int k, int[] enemy) {
        int index = 0;
        
        Queue<Node>q = new PriorityQueue<Node>();
        
        while(k>=0&&n>=0){
            if(index==enemy.length)
                return index;
            q.add(new Node(index, enemy[index]));
            n-=enemy[index];
            if(n<0){
                k--;
                n+=q.poll().value;
                if(n>=0)
                	index++;
            }else{
                index++;
            }
        }
        
        return index-1;
    }
}
