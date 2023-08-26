import java.util.*;
class Solution {
    public long solution(long n) {
        long answer = 0;
        String []num = String.valueOf(n).split("");
        Arrays.sort(num);
        String str = "";
        for(int i = num.length-1;i>=0;i--){
            str+=num[i];
        }
        return Long.parseLong(str);
    }
}