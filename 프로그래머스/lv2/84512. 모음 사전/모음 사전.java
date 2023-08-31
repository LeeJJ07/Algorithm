class Solution {
    static int count = 0;
    static int realcount = -1;
    static void dfs(String word, StringBuilder sb, String[]w) {
    	count++;
    	if(sb.length()==word.length()) {
    		if(word.equals(sb.toString()))
    			realcount = count;
    	}
    	if(sb.length()==5)
    		return;
    	for(int i = 0;i<5;i++) {
    		sb.append(w[i]);
    		dfs(word,sb,w);
    		sb.deleteCharAt(sb.length()-1);
    		if(realcount!=-1)
    			return;
    	}
    	
    }
    public int solution(String word) {
        
        // A E I O U;
        StringBuilder sb = new StringBuilder();
        String[]w = {"A","E","I","O","U"};
        count = 0;
        realcount = -1;
        dfs(word,sb,w);
        return realcount-1;
    }
}