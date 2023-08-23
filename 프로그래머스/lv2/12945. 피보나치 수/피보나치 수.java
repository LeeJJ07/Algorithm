class Solution {
    public int solution(int n) {
        long[]num = new long[100001];
        num[0] = 0;
        num[1] = 1;
        for(int i = 2;i<=n;i++){
            num[i] = num[i-1]+num[i-2];
            num[i]%=1234567;
        }
        return (int)num[n];
    }
}