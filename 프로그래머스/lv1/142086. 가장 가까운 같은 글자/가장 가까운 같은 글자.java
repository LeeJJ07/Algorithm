class Solution {
    public int[] solution(String s) {
        int[] answer = new int [s.length()];
        for(int i = 0;i<s.length();i++){
            int j,k;
            for(j = i-1, k = 0;j>=0;k++,j--){
                if(s.charAt(i)==s.charAt(j)){
                    break;
                }
            }
            if(k==i)
                k=-2;
            answer[i] = k+1;
        }
        return answer;
    }
}
