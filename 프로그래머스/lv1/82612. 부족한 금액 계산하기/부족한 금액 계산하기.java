class Solution {
    public long solution(int price, int money, int count) {
        long cost = (count*(count+1))/2;
        long resultcost = cost*price;
        if((long)money>=resultcost)
            return 0;
        return resultcost-money;
    }
}