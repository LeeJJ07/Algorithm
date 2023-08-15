import java.util.*;
class Solution {
    public int[] solution(String[] intStrs, int k, int s, int l) {
        ArrayList <Integer> result = new ArrayList<>();
        for(int i = 0;i<intStrs.length;i++){
            if(k<Integer.parseInt(intStrs[i].substring(s,s+l)))
                result.add(Integer.parseInt(intStrs[i].substring(s,s+l)));
        }
        return result.stream().mapToInt(x->x).toArray();
    }
}