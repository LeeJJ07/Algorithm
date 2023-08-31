import java.util.*;
class Solution {
    public int[] solution(String msg) {
        ArrayList<Integer>answer = new ArrayList<>();
        HashMap<String,Integer> hash = new HashMap<>();
        for(int i = 0;i<26;i++){
        	char a = (char) ('A'+i);
            hash.put(String.valueOf(a),i+1);
        }
        int idx = 27;
        for(int i = 0;i<msg.length();i++){
        	int j;
            for(j = i;j<msg.length();j++) {
            	String cmp = msg.substring(i,j+1);
            	if(!hash.containsKey(cmp)) {
            		hash.put(cmp, idx);
            		idx++;
            		answer.add(hash.get(cmp.substring(0,cmp.length()-1)));
            		break;
            	}
            }
            if(j==msg.length()) {
            	String cmp = msg.substring(i);
            	answer.add(hash.get(cmp));
            	break;
            }
            i = j-1;
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0;i<answer.size();i++) {
        	sb.append(answer.get(i));
        	
        }
        
        return answer.stream().mapToInt(x->x).toArray();
    }
}