import java.util.*;
class Solution {
    public String solution(int n, int t, int m, int p) {
        StringBuilder sb = new StringBuilder();
        int idx = 0;
        for(int i = 0;i<=t*m;i++) {
        	ArrayList<Integer>arr = new ArrayList<Integer>();
        	if(i==0)
        		arr.add(0);
        	int num = i;
        	while(num>0) {
        		arr.add(num%n);
        		num/=n;
        	}
        	for(int j = arr.size()-1;j>=0;j--) {
        		if(p-1 == idx%m) {
        			if(arr.get(j)>=10&&arr.get(j)<=15) {
        				char c = 'A';
        				c += arr.get(j)-10;
        				sb.append(c);
        			}
        			else {
        				sb.append(arr.get(j));
        			}
        			if(sb.length()==t)
        				break;
        		}
        		idx++;
        	}
        	if(sb.length()==t)
        		break;
        	
        }
        return sb.toString();
    }
}