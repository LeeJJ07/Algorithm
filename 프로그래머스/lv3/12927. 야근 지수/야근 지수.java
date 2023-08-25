import java.util.*;
class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        int stdnum = works[works.length-1];
        int idx = works.length-1;
        Arrays.sort(works);
        while(n>0){
            if(idx<0){
                idx = works.length-1;
                stdnum = works[works.length-1];
                continue;
            }
            if(works[idx]==stdnum){
                works[idx]--;
                idx--;
                n--;
            }else{
                idx = works.length-1;
                stdnum = works[works.length-1];
            }
        }
        for(int i = 0;i<works.length;i++){
            if(works[i]>0)
                answer+=works[i]*works[i];
        }
        return answer;
    }
}