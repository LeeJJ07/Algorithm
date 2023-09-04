import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        ArrayList<Integer>arr = new ArrayList<>();
        for(int i = 0;i<progresses.length;i++){
            arr.add((int)Math.ceil((double)(100-progresses[i])/speeds[i]));
        }
        ArrayList<Integer>result = new ArrayList<Integer>();
        int std = arr.get(0);
        int count = 1;
        for(int i = 1;i<arr.size();i++){
            if(std>=arr.get(i)){
                count++;
            }else{
                result.add(count);
                std = arr.get(i);
                count = 1;
            }
        }
        result.add(count);
        return result.stream().mapToInt(x->x).toArray();
    }
}