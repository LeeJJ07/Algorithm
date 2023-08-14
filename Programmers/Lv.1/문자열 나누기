class Solution {
    public int solution(String s) {
        int answer = 0;                //정답 카운트
        int idx = 0;                   
        int count1 =0;
        int count2 =0;
        char x = s.charAt(idx);
        while(true){
        	if(idx>=s.length()) {        //마지막으로 분리된 문자열
        		answer++;
        		break;
        	}
            if(s.charAt(idx)==x){ 
                count1++;
            }else{
                count2++;
            }
            idx++;
            if(count1==count2){
                answer++;
                count1=0;
                count2=0;
                if(idx<s.length()){
                    x=s.charAt(idx);
                }else {
                	break;
                }
            }
        }
        return answer;
    }
}
