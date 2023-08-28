import java.util.ArrayList;
class Solution {
    public int[] solution(int n, long left, long right) {
        ArrayList<Integer>arr = new ArrayList<>();
        for(long i = left; i<=right;i++){
            arr.add((int)Math.max(i%n,i/n)+1);
        }
        return arr.stream().mapToInt(x->x).toArray();
    }
}