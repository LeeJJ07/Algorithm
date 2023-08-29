import java.util.*;
class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        HashMap<String, Integer> h1 = new HashMap<String, Integer>();
        for(int i = 0;i<want.length;i++) {
        	h1.put(want[i], number[i]);
        }
        HashMap<String, Integer> h2 = new HashMap<String, Integer>();
        for(int i = 0;i<10;i++) {
        	h2.put(discount[i], h2.getOrDefault(discount[i], 0)+1);
        }
        for(int i = 0;i<=discount.length-10;i++) {
        	int j;
        	for(j = 0;j<want.length;j++) {
        		if(!h2.containsKey(want[j]))
        			break;
        		if(h1.get(want[j])!=h2.get(want[j]))
        			break;
        	}
        	if(j==want.length)
        		answer++;
        	if(i==discount.length-10)
        		break;
        	h2.put(discount[i], h2.get(discount[i])-1);
        	h2.put(discount[i+10], h2.getOrDefault(discount[i+10], 0)+1);
        	
        	//i번째는 빼고, i+10번째는 추가.
        }
        return answer;
    }
}