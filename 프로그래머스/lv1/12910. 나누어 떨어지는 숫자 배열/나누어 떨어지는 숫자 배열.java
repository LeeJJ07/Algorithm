import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        
        ArrayList <Integer>result = new ArrayList<Integer>();
        for(int i = 0;i<arr.length;i++){
            if(arr[i]%divisor==0)
                result.add(arr[i]);
        }
        if(result.size()==0)
            result.add(-1);
        Collections.sort(result);
        return result.stream().mapToInt(x->x).toArray();
    }
}