class Solution {
    public int solution(int n) {
        n--;
        for(int i =2;i<=n;i++){
            if(n%i==0)
                return i;
        }
        return 0;
    }
}