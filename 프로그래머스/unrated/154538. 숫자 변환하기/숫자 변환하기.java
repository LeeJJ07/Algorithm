import java.util.*;
class Solution {
    public int solution(int x, int y, int n) {
        int answer = 0;
        
        Queue<Integer>q = new LinkedList<Integer>();
        q.add(x);
        int []check = new int[1000001];
    
        while(!q.isEmpty()) {
        	int size = q.size();
        	for(int i = 0;i<size;i++) {
        		int num = q.poll();
        		if(num>y)
        			continue;
        		if(num==y) {
        			return answer;
        		}
                if(check[num]==1)
                    continue;
                else{
                    check[num] = 1;
                }
        		q.add(num+n);
        		q.add(num*2);
        		q.add(num*3);
        	}

        	answer++;
        }
        
        return -1;
    }
}