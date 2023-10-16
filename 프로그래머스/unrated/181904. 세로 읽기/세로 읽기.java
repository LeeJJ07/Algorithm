class Solution {
    public String solution(String my_string, int m, int c) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0;i<my_string.length()/m;i++) {
        	sb.append(my_string.charAt(i*m + c-1));
        }
        return sb.toString();
    }
}