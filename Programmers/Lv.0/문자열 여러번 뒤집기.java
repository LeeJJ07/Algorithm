class Solution {
    public String solution(String my_string, int[][] queries) {
        
        String[]str = my_string.split("");
        for(int i = 0;i<queries.length;i++){
            int mid = (queries[i][0]+queries[i][1])/2;
            for(int j = 1; j <= queries[i][1]-mid ;j++){
               if(queries[i][1]-mid == mid - queries[i][0]) {  // 중간값을 기준으로 양쪽 개수가 같을 때
            	   String temp = str[mid-j];
            	   str[mid-j] = str[mid+j];
            	   str[mid+j] = temp;
               }else {                                        // 중간값을 기준으로 양쪽 개수가 다를 때
            	   String temp = str[mid-j+1];
            	   str[mid-j+1] = str[mid+j];
            	   str[mid+j] = temp;
               }
            }
        }
        String answer= "";
        for(int i = 0;i<str.length;i++){
            answer+=str[i];
        }
        return answer;
    }
}
