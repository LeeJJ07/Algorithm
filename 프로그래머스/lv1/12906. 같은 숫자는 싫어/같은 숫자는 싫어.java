import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        ArrayList <Integer>result = new ArrayList<>();
        int before = arr[0];
        result.add(before);
        for(int i = 1;i<arr.length;i++){
            if(before!=arr[i]){
                before = arr[i];
                result.add(before);
            }
        }

        return result.stream().mapToInt(x->x).toArray();
    }
}