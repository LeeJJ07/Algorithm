import java.util.*;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
class Solution {
    public String solution(String s) {
        StringBuilder sb = new StringBuilder();
    	String []aa = s.split("");
    	Arrays.sort(aa, Collections.reverseOrder());
    	for(int i = 0;i<aa.length;i++) {
    		sb.append(aa[i].charAt(0));
    	}
        
        return sb.toString();
    }
}