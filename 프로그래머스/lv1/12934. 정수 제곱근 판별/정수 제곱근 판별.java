class Solution {
    public long solution(long n) {
        long answer = 0;
        double num = Math.sqrt(n);
        if((int)num == num)
            return (long)Math.pow(num+1,2);
        return -1;
    }
}