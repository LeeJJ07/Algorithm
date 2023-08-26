class Solution {
    public int solution(int[] arr) {
        int answer = 0;
        int num = arr[arr.length-1];
        while(true){
            int i;
            for(i = 0;i<arr.length-1;i++){
                if(num%arr[i]!=0)
                    break;
            }
            if(i==arr.length-1)
                break;
            num+=arr[arr.length-1];
        }
        return num;
    }
}