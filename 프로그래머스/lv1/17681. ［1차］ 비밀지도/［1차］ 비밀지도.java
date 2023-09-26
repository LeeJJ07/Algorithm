class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        int [][]map = new int[n][n];
        for(int i = 0;i<n;i++){
            for(int j =n-1;j>=0;j-- ){
                map[i][j] = (arr1[i]%2)|(arr2[i]%2);
                arr1[i]/=2;
                arr2[i]/=2;
            }
        }
        for(int i = 0;i<n;i++){
            StringBuilder sb = new StringBuilder();
            for(int j = 0;j<n;j++){
                if(map[i][j]==0)
                    sb.append(" ");
                else
                    sb.append("#");
            }
            answer[i] = sb.toString();
        }
        return answer;
    }
}