import java.util.*;
class Solution {
    public int solution(int[] citations) {
        Arrays.sort(citations);
        int i, j = -1;
        for(i = citations[citations.length-1];i>=0;i--) {
        	for(j = citations.length-1;j>=0;j--) {
        		if(j!=0&&citations[j]==citations[j-1])
        			continue;
        		if(citations[j]>=i&&i==citations.length-j)
        			break;
        	}
        	if(j!=-1)
        		break;
        }
        if(i==-1)
        	return 0;
        return i;
    }
}