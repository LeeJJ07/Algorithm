class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        int w = Math.max(sizes[0][0],sizes[0][1]);
        int h = Math.min(sizes[0][0],sizes[0][1]);
        for(int i = 1;i<sizes.length;i++){
            w = Math.max(w,Math.max(sizes[i][0],sizes[i][1]));
            h = Math.max(h,Math.min(sizes[i][0],sizes[i][1]));
        }
        
        return w*h;
    }
}