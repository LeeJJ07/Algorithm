import java.util.*;
class Solution {
    public int solution(int[] topping) {
        
        HashMap<Integer, Integer> hash1 = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> hash2 = new HashMap<Integer, Integer>();
		int answer = 0;
		for(int i =0;i<topping.length;i++) {
			hash2.put(topping[i], hash2.getOrDefault(topping[i], 0)+1);
		}
		for(int i = 0;i<topping.length;i++) {
			if(hash2.containsKey(topping[i])) {
				hash2.put(topping[i], hash2.get(topping[i])-1);
				if(hash2.get(topping[i])==0)
					hash2.remove(topping[i]);
			}
			hash1.put(topping[i],hash1.getOrDefault(topping[i], 0)+1);
			if(hash1.size()==hash2.size())
				answer++;
		}
		
		return answer;
    }
}
