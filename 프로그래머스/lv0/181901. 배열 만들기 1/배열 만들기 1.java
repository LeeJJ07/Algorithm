import java.util.*;
class Solution {
    public int[] solution(int n, int k) {
        ArrayList<Integer>arr = new ArrayList<>();
        for(int i = 1;i*k<=n;i++){
            arr.add(i*k);
        }
        return arr.stream().mapToInt(x->x).toArray();
    }
}
