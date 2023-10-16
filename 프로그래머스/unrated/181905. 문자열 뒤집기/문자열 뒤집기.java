class Solution {
    public String solution(String my_string, int s, int e) {
        StringBuilder sb = new StringBuilder();
      	sb.append(my_string.substring(0,s));
      	for(int i = e; i>=s;i--) {
      		sb.append(my_string.charAt(i));
      	}
      	sb.append(my_string.substring(e+1));
        return sb.toString();
    }
}