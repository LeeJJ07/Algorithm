import java.util.*;
class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        for(int i = 0;i<cities.length;i++) {
        	cities[i] = cities[i].toLowerCase();
        }
        Queue<String>q = new LinkedList<String>();
        
        for(int i = 0;i<cities.length;i++) {
            if(cacheSize==0){
                answer+=5;
                continue;
            }
        	if(q.size()==cacheSize) {
        		if(q.contains(cities[i])) {
        			q.remove(cities[i]);
        			q.add(cities[i]);
        			answer+=1;
        		}else {
        			answer+=5;
        			q.poll();
        			q.add(cities[i]);
        		}
        	}else {
        		if(q.contains(cities[i])) {
        			q.remove(cities[i]);
        			q.add(cities[i]);
					answer += 1;
				} else {
					q.add(cities[i]);
					answer += 5;
				}
        	}
        }
        return answer;
    }
}