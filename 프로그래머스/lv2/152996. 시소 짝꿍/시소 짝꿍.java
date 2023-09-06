import java.util.*;
class Solution {
    public long solution(int[] weights) {
        long answer = 0;
        HashMap<Integer, Long> hash = new HashMap<>();
        
        for(int i = 0;i<weights.length;i++){
            hash.put(weights[i], hash.getOrDefault(weights[i], (long)0)+1);
        }
        
        for (Map.Entry<Integer, Long> pair1 : hash.entrySet()) {
            //pair.getKey(), pair.getValue()
        	for (Map.Entry<Integer, Long> pair2 : hash.entrySet()) {
                if(pair1.getKey()==pair2.getKey()) {
                	answer+=(pair1.getValue()*(pair1.getValue()-1))/2;
                }else if(pair1.getKey()*2==pair2.getKey()) {
                	answer+=(pair1.getValue()*pair2.getValue());
                }else if(pair1.getKey()*4==pair2.getKey()*3){
                    answer+=(pair1.getValue()*pair2.getValue());
                }else if(pair1.getKey()*3==pair2.getKey()*2){
                    answer+=(pair1.getValue()*pair2.getValue());;
                }
            }
        }
        
        return answer;
    }
}
