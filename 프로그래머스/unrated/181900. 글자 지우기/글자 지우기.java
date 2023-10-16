class Solution {
    public String solution(String my_string, int[] indices) {
        StringBuilder sb = new StringBuilder();
        sb.append(my_string);
        for(int i = 0;i<indices.length;i++){
            sb.replace(indices[i],indices[i]+1," ");
        }
        return sb.toString().replaceAll(" ", "");
    }
}