class Solution {
    static int answer = 100;
    static void dfs(boolean []check, String[]words, String word, 
                    String target, int level){
        if(word.equals(target)){
            if(level<answer)
                answer=level;
            return;
        }
        for(int i = 0;i<words.length;i++){
            if(check[i])
                continue;
            int strNumC = 0;
            for(int j = 0;j<words[i].length();j++){
                if(word.charAt(j)!=words[i].charAt(j)){
                    strNumC++;
                }
            }
            if(strNumC==1){
                check[i] = true;
                dfs(check, words,words[i], target, level+1);
            }
        }
    }
    public int solution(String begin, String target, String[] words) {
        
        for(int i = 0;i<words.length;i++){
            int strNumC = 0;
            boolean []check = new boolean[words.length];
            for(int j = 0;j<words[i].length();j++){
                if(begin.charAt(j)!=words[i].charAt(j)){
                    strNumC++;
                }
            }
            if(strNumC==1){
                check[i] = true;
                dfs(check, words,words[i], target, 1);
            }
        }
        if(answer==100)
            return 0;
        return answer;
    }
}