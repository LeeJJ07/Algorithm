class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        String []pos = {"aya","ye","woo","ma"};
        for(int i = 0;i<babbling.length;i++){
            String before = "";
            for(int j = 0;j<pos.length;j++){
                if(before.equals(pos[j]))
                    continue;
                if(babbling[i].length()<pos[j].length())
                	continue;
                if(babbling[i].substring(0,pos[j].length()).equals(pos[j])){
                    babbling[i] = babbling[i].substring(pos[j].length(),babbling[i].length());
                    before = pos[j];
                    if(babbling[i].length()==0)
                        break;
                    j=-1;
                }
            }
            if(babbling[i].length()==0)
                answer++;
        }
        return answer;
    }
}
