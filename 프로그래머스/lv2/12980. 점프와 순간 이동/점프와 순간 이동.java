import java.util.*;

public class Solution {
    public int solution(int n) {

        int answer=0;
        if(n==1)
            return 1;
        while(n>=0){
            if(n%2==1){
                answer++;
            }
            n/=2;
            if(n==1)
                break;
        }
        return answer+1;
        
    }
}