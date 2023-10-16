class Solution {
    public int solution(String my_string, String is_prefix) {
        if(my_string.length()<is_prefix.length())
            return 0;
        return my_string.substring(0,is_prefix.length()).equals(is_prefix)? 1 : 0;
    }
}