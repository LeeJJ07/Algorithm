import java.util.*;
class Solution {
    public String solution(String X, String Y) {
        String answer = "";
        int []x = new int[10];
        int []y = new int[10];
        for(int i = 0;i<X.length();i++){
            x[X.charAt(i)-'0']++;
        }
        for(int i = 0;i<Y.length();i++){
            y[Y.charAt(i)-'0']++;
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 9;i>=0;i--){
        	for(int j = 0;j<Math.min(y[i], x[i]);j++) {
        		sb.append(i);
        	}
        	if(i==1&&sb.length()==0&&x[0]!=0&&y[0]!=0)
        		return "0";
        		
        }
        answer = sb.toString();
        if(answer.equals(""))
            return "-1";
        
        return answer;
    }
}