import java.util.ArrayList;
class Solution {
    public int solution(int n) {
        int answer = 0;
        ArrayList<Integer>arr = new ArrayList<>();
        while(n>0){
            arr.add(n%3);
            n/=3;
        }
        int k = 1;
        for(int i = arr.size()-1;i>=0;i--){
            answer+=arr.get(i)*k;
            k*=3;
        }
        return answer;
    }
}