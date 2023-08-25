class Solution {
    public int solution(String my_string, String is_suffix) {

        for(int i = 0;i<my_string.length();i++){
            if(my_string.substring(i).compareTo(is_suffix)==0)
                return 1;
        }
        return 0;

    }
}
