import java.util.*;
class Solution {
    static class Node{
    	int idx;
    	double fail;
    	Node(int idx, double fail){
    		this.idx = idx;
    		this.fail = fail;
    	}
    }
    public int[] solution(int N, int[] stages) {
        HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();
        
        for(int i = 0;i<stages.length;i++) {
        	hash.put(stages[i], hash.getOrDefault(stages[i], 0)+1);
        }
        int person = stages.length;
        Node []n = new Node[N];
        for(int i = 0;i<N;i++) {
        	double f;
        	if(hash.containsKey(i+1)) {
        		f = (double)hash.get(i+1)/(double)person;
        		person-=hash.get(i+1);
        	}
        	else
        		f = 0;
        	n[i] = new Node(i+1,f);
        	
        }
        Arrays.sort(n,new Comparator<Node>() {
        	@Override
        	public int compare(Node o1, Node o2) {
        		// TODO Auto-generated method stub
        		if(o1.fail<o2.fail)
        			return 1;
                else if(o1.fail==o2.fail){
                    if(o1.idx>=o2.idx)
                        return 1;
                    else
                        return -1;
                }
        		else
        			return -1;
        	}
		});
        int[] answer = new int[N];
        for(int i = 0;i<N;i++) {
        	answer[i] = n[i].idx;
        }
        return answer;
    }
}