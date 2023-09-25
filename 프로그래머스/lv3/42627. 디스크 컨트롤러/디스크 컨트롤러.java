import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        Arrays.sort(jobs,new Comparator<int[]>() {
        	@Override
        	public int compare(int[] o1, int[] o2) {
        		if(o1[0]>o2[0]) {
        			return 1;
        		}else if(o1[0]==o2[0]) {
        			if(o1[1]>o2[1])
        				return 1;
        			else
        				return -1;
        		}else {
        			return -1;
        		}
        	}
		});
        answer+=jobs[0][1];
        int nextTime = jobs[0][0]+jobs[0][1];
        int []check = new int[jobs.length];
        check[0] = 1;
        
        for(int count = 1;count<jobs.length;count++) {
        	int min = 1001;
        	int minidx = 0;
        	int i;
        	for(i = 1;i<jobs.length;i++) {
        		if(check[i]==1)
        			continue;
        		if(jobs[i][0]<nextTime && min>jobs[i][1]) {
        			min = jobs[i][1];
        			minidx = i;
        		}
        	}
        	if(minidx==0) {
        		for(int j = 0;j<jobs.length;j++) {
        			if(check[j]==0) {
        				minidx = j;
        				nextTime = jobs[j][1]+jobs[j][0];
                        break;
        			}
        		}
        	}else {
				nextTime += jobs[minidx][1];
        	}
        	check[minidx] = 1;
        	answer+=(nextTime-jobs[minidx][0]);
        }
        
        
        
        return answer/jobs.length;
    }
}