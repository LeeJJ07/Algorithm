import java.util.*;
class Solution {
    public int solution(int[][] data, int col, int row_begin, int row_end) {
        Arrays.sort(data, new Comparator<int[]>() {
    		@Override
    		public int compare(int[] o1, int[] o2) {
    			// TODO Auto-generated method stub
    			if(o1[col-1]>o2[col-1]) {
    				return 1;
    			}else if(o1[col-1]<o2[col-1]) {
    				return -1;
    			}else {
    				if(o1[0]>o2[0])
    					return -1;
    				else
    					return 1;
    			}
    		}
		});
    	int answer = 0;
    	for(int i = row_begin-1;i<=row_end-1;i++) {
    		int sum = 0;
    		for(int j = 0;j<data[i].length;j++) {
    			sum+=(data[i][j]%(i+1));
    		}
    		if(i==row_begin-1) {
    			answer = sum;
    		}else {
    			answer = answer^sum;
    		}
    	}

        return answer;
    }
}
