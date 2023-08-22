class Solution {
    public int solution(int n) {
        int answer = 0;
        int count = 0;
        int num = n;
        while(true){
            if(num==0)
                break;
            if(num%2==1)  //1의 개수 카운트
                count++;
            num/=2;
        }
        for(int i = n+1;;i++){
            int count1 = 0;
            num = i;
            while(true){
                if(num==0)
                    break;
                if(num%2==1)  //1의 개수 카운트
                    count1++;
                num/=2;
            }
            if(count1==count){
                answer=i;
                break;
            }
        }
        return answer;
    }
}