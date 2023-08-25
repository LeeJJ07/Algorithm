class Solution {
    public int solution(int number, int limit, int power) {
        int answer = 0;
        for(int i = 1;i<=number;i++){
            int count = 1;
            for(int j = 2;j<Math.sqrt(i);j++){
                if(i%j==0)
                    count++;
            }
            if(i!=1)
                count*=2;
            if(i!=1&&Math.sqrt(i)==(int)Math.sqrt(i)){
                count++;
            }
            if(count>limit)
                answer+=power;
            else
                answer+=count;
        }
        return answer;
    }
}
