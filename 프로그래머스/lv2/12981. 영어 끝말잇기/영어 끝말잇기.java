import java.util.*;
class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[2];
        Set<String>set = new HashSet<String>();
        set.add(words[0]);
        char lastword = words[0].charAt(words[0].length()-1);
        int personNum = 1;
        int i;
        for(i = 1;i<words.length;i++){
        	if(set.contains(words[i])||words[i].length()==1)
                break;
            if(lastword == words[i].charAt(0)){
                lastword = words[i].charAt(words[i].length()-1);
                set.add(words[i]);
            }else{
                break;
            }
            
            personNum=(personNum+1)%n;
        }
        if(words.length==i){
            answer[0] = 0;answer[1] = 0;
        }else{
            answer[0] = personNum+1;
            answer[1] = i/n+1;
        }
        return answer;
    }
}