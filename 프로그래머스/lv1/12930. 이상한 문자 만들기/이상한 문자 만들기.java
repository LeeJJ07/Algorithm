class Solution {
    public String solution(String s) {
        StringBuilder sb = new StringBuilder();
        int start = 0;
        for(int i = 0;i<s.length();i++){
            if(s.charAt(i)==' '){
                start = 0;
                sb.append(" ");
                continue;
            }
            if(start%2==0)
                sb.append(String.valueOf(s.charAt(i)).toUpperCase());
            else
                sb.append(String.valueOf(s.charAt(i)).toLowerCase());
            start++;
        }
        return sb.toString();
    }
}