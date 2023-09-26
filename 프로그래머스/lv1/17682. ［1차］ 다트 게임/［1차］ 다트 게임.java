
class Solution {
    public int solution(String dartResult) {
        int []num = new int[3];
        int []dn = new int[3];
        int idx = -1;
        for(int i = 0;i<dartResult.length();i++){
            if(dartResult.charAt(i)>='0' && dartResult.charAt(i)<='9'){
                idx++;
                if(dartResult.charAt(i+1)=='0'){
                    num[idx] = 10;
                    i+=1;
                }else {
                	num[idx] = dartResult.charAt(i)-'0';
                }
            }
            if(dartResult.charAt(i)=='S')
                num[idx] = (int)Math.pow(num[idx], 1);
            else if(dartResult.charAt(i)=='D')
                num[idx] = (int)Math.pow(num[idx],2);
            else if(dartResult.charAt(i)=='T')
                num[idx] = (int)Math.pow(num[idx],3);
            if(dartResult.charAt(i)=='#')
                num[idx] *= -1;
            if(dartResult.charAt(i)=='*')
                dn[idx]++;
        }
        if(dn[0]==1){
            num[0]*=2;
        }
        if(dn[1]==1){
            num[0]*=2;
            num[1]*=2;
        }
        if(dn[2]==1){
            num[2]*=2;
            num[1]*=2;
        }
        return num[0]+num[1]+num[2];
    }
}