class Solution {
    public String solution(String[] survey, int[] choices) {
        
        int []score = new int[4];
        
        for(int i = 0;i<survey.length;i++){
            if(survey[i].charAt(0)=='R'){
                score[0]+=(choices[i]-4);
            }else if(survey[i].charAt(0)=='T'){
                score[0]+=(8-choices[i]-4);
            }else if(survey[i].charAt(0)=='C'){
                score[1]+=(choices[i]-4);
            }else if(survey[i].charAt(0)=='F'){
                score[1]+=(8-choices[i]-4);
            }else if(survey[i].charAt(0)=='J'){
                score[2]+=(choices[i]-4);
            }else if(survey[i].charAt(0)=='M'){
                score[2]+=(8-choices[i]-4);
            }else if(survey[i].charAt(0)=='A'){
                score[3]+=(choices[i]-4);
            }else if(survey[i].charAt(0)=='N'){
                score[3]+=(8-choices[i]-4);
            }
        }
        String answer = "";
        //R-T, C-F, J-M, A-N;
        if(score[0]<=0){
            answer+="R";
        }else{
            answer+="T";
        }
        if(score[1]<=0){
            answer+="C";
        }else{
            answer+="F";
        }
        if(score[2]<=0){
            answer+="J";
        }else{
            answer+="M";
        }
        if(score[3]<=0){
            answer+="A";
        }else{
            answer+="N";
        }
        
        return answer;
    }
}