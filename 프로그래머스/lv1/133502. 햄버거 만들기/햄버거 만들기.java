import java.util.*;
class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        ArrayList<Integer>arr = new ArrayList<>();
        for(int i = 0 ;i<ingredient.length;i++){
            arr.add(ingredient[i]);
        }
        for(int i = 3;i<arr.size();i++){
            if(arr.get(i)==1&&arr.get(i-1)==3&&arr.get(i-2)==2&&arr.get(i-3)==1){
                answer++;
                arr.remove(i);arr.remove(i-1);
                arr.remove(i-2);arr.remove(i-3);
                i-=4;
                if(i<3) i=2;
            }
        }
        return answer;
    }
}
