class Solution {
    boolean solution(String s) {
        boolean answer = true;

        int yC = 0;
        int pC = 0;
        s = s.toLowerCase();
        for(int i = 0;i<s.length();i++){
            if(s.charAt(i)=='y')
                yC++;
            else if(s.charAt(i)=='p')
                pC++;
        }
        if(yC!=pC)
            answer = false;
        return answer;
    }
}