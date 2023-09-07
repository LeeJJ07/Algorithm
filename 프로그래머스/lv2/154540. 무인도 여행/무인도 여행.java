import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
class Solution {
    static class Node{
    	int x;
    	int y;
    	Node(int x, int y){
    		this.x = x;
    		this.y = y;
    	}
    }
    
    static int []mx = {-1,0,1,0};
    static int []my = {0,1,0,-1};
    
    static int bfs(int[][]map, int[][]check,int x, int y){
        int count = map[x][y];
    	check[x][y] = 1;
    	Queue<Node>q = new LinkedList<Node>();
    	q.add(new Node(x,y));
    	
    	while(q.size()!=0) {
    		Node n = q.poll();
    		for(int i = 0;i<4;i++) {
    			int nx = n.x+mx[i];
    			int ny = n.y+my[i];
    			
    			if(nx<0||ny<0||nx>=map.length||ny>=map[0].length)
    				continue;
    			if(check[nx][ny]==1)
    				continue;
    			if(map[nx][ny]==0)
    				continue;
    			q.add(new Node(nx,ny));
    			check[nx][ny] = 1;
    			count+=map[nx][ny];
    		}
    	}
    	
    	return count;
    }

	public int[] solution(String[] maps) {
        ArrayList<Integer>answer = new ArrayList<>();
        int[][]map = new int[maps.length][maps[0].length()];
        for(int i = 0;i<map.length;i++){
            for(int j = 0;j<map[i].length;j++){
                if(maps[i].charAt(j)=='X')
                    map[i][j] = 0;
                else
                    map[i][j] = Integer.parseInt(maps[i].substring(j, j+1));
            }
        }
        int [][]check = new int[map.length][map[0].length];
        for(int i = 0;i<map.length;i++) {
        	for(int j = 0;j<map[i].length;j++) {
        		if(map[i][j]==0)
        			continue;
        		if(check[i][j]==1)
        			continue;
        		answer.add(bfs(map,check,i,j));
        	}
        }
        Collections.sort(answer);
        if(answer.size()==0)
            answer.add(-1);
        return answer.stream().mapToInt(x->x).toArray();
    }
}
