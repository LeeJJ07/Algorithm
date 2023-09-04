import java.util.*;
class Solution {
    public int solution(int[] priorities, int location) {
        Queue<Integer>q = new LinkedList<Integer>();
    	ArrayList<Integer>arr = new ArrayList<Integer>();
    	for(int i = 0;i<priorities.length;i++) {
    		q.add(i);
    		arr.add(priorities[i]);
    	}
    	Collections.sort(arr);
    	int idx = arr.size()-1;
        int count = 0;
    	while(true) {
    		if(q.size()==0)
    			break;
    		if(idx>=arr.size())
    			break;
    		int a = q.poll();
    		if(priorities[a]==arr.get(idx)) {
    			idx--;
                count++;
                if(a==location)
    				break;
    		}else{
    		    q.add(a);
            }
    	}
        return count;
    }
}