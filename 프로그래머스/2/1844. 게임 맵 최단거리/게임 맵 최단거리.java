import java.util.*;
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
	
    public int solution(int[][] maps) {
        int [][]check = new int[maps.length][maps[0].length];
        check[0][0] = 1;
        Queue<Node> q = new LinkedList<Node>();
        q.add(new Node(0,0));
        int level = 1;
        boolean find = false;
        while(q.size()>0) {
        	int size = q.size();
        	for(int k = 0;k<size;k++) {
        		Node n = q.poll();
				for (int i = 0; i < 4; i++) {
					int nx = n.x + mx[i];
					int ny = n.y + my[i];
					if (nx < 0 || ny < 0 || nx >= maps.length || ny >= maps[0].length)
						continue;
					if (check[nx][ny] == 1)
						continue;
					if (maps[nx][ny] == 0)
						continue;
					check[nx][ny] = 1;
					if (nx == maps.length - 1 && ny == maps[0].length - 1) {
						find = true;
						break;
					}
					q.add(new Node(nx, ny));
				}
				if(find)
					break;
        	}
        	if(find)
        		break;
        	level++;
        }
        if(!find)
        	return -1;
        return level+1;
    }
}