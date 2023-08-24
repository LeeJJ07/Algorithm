class Solution {
    public int solution(int[][] triangle) {
        for(int i = triangle.length-2;i>=0;i--){
            for(int j = 0;j<=i;j++){
                int sum = triangle[i+1][j]>
                    triangle[i+1][j+1] ? triangle[i+1][j]:triangle[i+1][j+1];
                triangle[i][j]+=sum;
            }
        }
        return triangle[0][0];
    }
}