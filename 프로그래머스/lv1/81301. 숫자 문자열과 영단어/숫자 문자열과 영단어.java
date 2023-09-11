import java.util.*;
class Solution {
    public int solution(String s) {
        int answer = 0;
        String []num = {"zero","one","two","three","four","five","six",
                       "seven","eight","nine"};
        StringBuilder number = new StringBuilder();
        int idx = 0;
        while(idx<s.length()){
        	int i;
            for(i = 0;i<num.length;i++) {
            	if(idx+num[i].length()>s.length())
            		continue;
            	String str = s.substring(idx,idx + num[i].length());
            	if(str.equals(num[i])) {
            		idx += num[i].length();
            		number.append(i);
            		break;
            	}
            }
            if(i == num.length) {
            	number.append(s.subSequence(idx, idx+1));
            	idx++;
            }
        }
        return Integer.parseInt(number.toString());
    }
}