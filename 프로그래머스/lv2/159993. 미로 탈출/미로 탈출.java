import java.util.*;
class Solution {
    static int[]mx = {-1,0,1,0};
    static int[]my = {0,1,0,-1};
    static class Node{
    	int x;
    	int y;
    	Node(int x, int y){
    		this.x = x;
    		this.y = y;
    	}
    }
    static int bfs(String[]maps, int sx, int sy, int ex, int ey, char target) {
    	Queue<Node> q = new LinkedList<Node>();
    	int level = 1;
    	int[][]check = new int[maps.length][maps[0].length()];
    	q.add(new Node(sx,sy));
    	while(!q.isEmpty()) {
    		int size = q.size();
    		for(int i = 0;i<size;i++) {
    			Node n = q.poll();
    			for(int j = 0;j<4;j++) {
    				int nx = n.x+mx[j];
    				int ny = n.y+my[j];
    				if(nx<0||ny<0||nx>=maps.length||ny>=maps[0].length())
    					continue;
    				if(maps[nx].charAt(ny)==target) {
    					return level;
    				}
    				if(maps[nx].charAt(ny)=='X')
    					continue;
    				if(check[nx][ny]==1)
    					continue;
    				check[nx][ny] = 1;
    				q.add(new Node(nx,ny));
    			}
    			
    		}
    		level++;
    	}
    	return -1;
    }
    public int solution(String[] maps) {
        int answer = 0;
        Node start = null, end = null, lab = null;
        for(int i = 0;i<maps.length;i++) {
        	for(int j = 0;j<maps[i].length();j++) {
        		if(maps[i].charAt(j)=='S') {
        			start = new Node(i,j);
        		}else if(maps[i].charAt(j)=='E') {
        			end = new Node(i,j);
        		}else if(maps[i].charAt(j)=='L') {
        			lab = new Node(i,j);
        		}
        	}
        }
        int result = bfs(maps,start.x,start.y,lab.x,lab.y,'L');
        if(result==-1) {
        	return -1;
        }else {
        	answer+=result;
        }
        result = bfs(maps,lab.x,lab.y,end.x,end.y,'E');
        if(result == -1) {
        	return -1;
        }else {
        	answer+=result;
        }
        return answer;
    }
}
