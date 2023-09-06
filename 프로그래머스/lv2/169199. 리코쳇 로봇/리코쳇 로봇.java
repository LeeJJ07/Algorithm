import java.util.*;
class Solution {
    static int result = 0;
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
    static void bfs(String[]board, int[][]check,int x, int y) {
    	
    	boolean find = false;
    	check[x][y] = 1;
    	Queue<Node>q = new LinkedList<Node>();
    	q.add(new Node(x,y));
    	int Size = 1;
    	int level = 1;
    	while(q.size()>0) {
    		for(int i = 0;i<Size;i++) {
    			Node n = q.poll();
    			for(int j = 0;j<4;j++) {
    				int nx = n.x;
    				int ny = n.y;
    				while(true) {
    					nx+=mx[j];
    					ny+=my[j];
    					if(nx<0||ny<0||nx>=check.length||ny>=check[0].length)
    						break;
    					if(board[nx].charAt(ny)=='D')
    						break;
    				}
    				nx-=mx[j];
    				ny-=my[j];
    				if(check[nx][ny]==0) {
    					check[nx][ny] = 1;
    					q.add(new Node(nx,ny));
    				}
    				if(board[nx].charAt(ny)=='G') {
    					find = true;
    					result = level;
    					return;
    				}
    			}
    		}

    		level++;
    		Size = q.size();
    	}
    	return ;
    }
    
    public int solution(String[] board) {
    	int[][]check = new int[board.length][board[0].length()];
    	int level = -1;
    	for(int i = 0;i<board.length;i++) {
    		for(int j = 0;j<board[i].length();j++) {
    			if(board[i].charAt(j)=='R')
    				bfs(board, check, i, j);
    		}
    	}
    	if(result==0)
    		return -1;
    	return result;
    }
}
