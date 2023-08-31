import java.util.ArrayList;
class Solution {
    public int[] solution(int[] arr) {
        ArrayList<Integer>answer = new ArrayList<>();
        int minvalue = arr[0];
        int minidx = 0;
        answer.add(arr[0]);
        for(int i = 1;i<arr.length;i++){
            answer.add(arr[i]);
            if(arr[i]<minvalue){
                minidx = i;
                minvalue = arr[i];
            }
        }
        answer.remove(minidx);
        if(answer.size()==0)
            answer.add(-1);
        return answer.stream().mapToInt(x->x).toArray();
    }
}