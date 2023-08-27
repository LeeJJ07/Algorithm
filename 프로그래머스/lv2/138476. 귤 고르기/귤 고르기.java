import java.util.*;
class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        HashMap<Integer, Integer>map = new HashMap<>();
        for(int i = 0;i<tangerine.length;i++) {
        	map.put(tangerine[i],map.getOrDefault(tangerine[i], 0)+1);
        }
        List<Map.Entry<Integer, Integer>> entryList = new LinkedList<>(map.entrySet());
        entryList.sort(new Comparator<Map.Entry<Integer, Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
        	return o2.getValue() - o1.getValue();
            }
        });
        for(int i = 0;i<entryList.size();i++) {
        	if(k<=0)
        		break;
        	answer++;
        	k-=entryList.get(i).getValue();
        }
        return answer;
    }
}
