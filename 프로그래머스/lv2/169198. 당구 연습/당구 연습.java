import java.util.*;
class Solution {
    public int[] solution(int m, int n, int startX, int startY, int[][] balls) {
        ArrayList <Integer> result = new ArrayList<>();
        for(int i = 0;i<balls.length;i++){
            double min = 1000000000;
            int x = startX;
            int y = startY;
            int a = balls[i][0];
            int b = balls[i][1];
            //왼쪽 위 모서리와 오른쪽 아래 모서리를 잇는 대각선 상에 두 공이 있을 경우
            if(n*x + m*y == m*n && n*a+m*b==m*n){
                if(x<a){
                    if(Math.pow(a+x,2)+Math.pow(2*n-b-y,2)<min){
                        min = Math.pow(a+x,2)+Math.pow(2*n-b-y,2);
                    }
                }else{
                   if(Math.pow(b+y,2)+Math.pow(2*m-a-x,2)<min){ 
                       min = Math.pow(b+y,2)+Math.pow(2*m-a-x,2);
                   }
                }
            }
            //오른쪽 위 모서리와 왼쪽 아래 모서리를 잇는 대각선 상에 두 공이 있을 경우
            else if(m*a==n*b&&m*x==n*y){
                if(x<a){
                    if(Math.pow(x+a,2)+Math.pow(y+b,2)<min){
                        min = Math.pow(x+a,2)+Math.pow(y+b,2);
                    }
                }else{
                    if(Math.pow(2*m-x-a,2)+Math.pow(2*n-y-b,2)<min){
                        min = Math.pow(2*m-x-a,2)+Math.pow(2*n-y-b,2);
                    }
                }
            }
            //세로로 배치된 경우
            if(x == a){
                if(y>b){
                    if(min>Math.pow(2*n-y-b,2)){
                        min = Math.pow(2*n-y-b,2);
                    }
                }else{
                    if(min>Math.pow(y+b,2)){
                        min = Math.pow(y+b,2);
                    }
                }
                //왼쪽 원쿠션
				if (min > Math.pow(x + a, 2) + Math.pow(y - b, 2)) {
					min = Math.pow(x + a, 2) + Math.pow(y - b, 2);
				}
				//오른쪽 원쿠션
				if (min > Math.pow(2 * m - x - a, 2) + Math.pow(y - b, 2)) {
					min = Math.pow(2 * m - x - a, 2) + Math.pow(y - b, 2);
				}
            }
            //가로로 배치된 경우
            if(y == b){
                if(x>a){
                    if(min>Math.pow(2*m-x-a,2)){
                        min = Math.pow(2*m-x-a,2);
                    }
                }else{
                    if(min>Math.pow(x+a,2)){
                        min = Math.pow(x+a,2);
                    }
                }
                //위 원쿠션
				if (min > Math.pow(2 * n - y - b, 2) + Math.pow(x - a, 2)) {
					min = Math.pow(2 * n - y - b, 2) + Math.pow(x - a, 2);
				}
				//아래 원크션
				if (min > Math.pow(y + b, 2) + Math.pow(x - a, 2)) {
					min = Math.pow(y + b, 2) + Math.pow(x - a, 2);
				}
            }
            if(x!=a && y!=b) {
            	//위 원쿠션
				if (min > Math.pow(2 * n - y - b, 2) + Math.pow(x - a, 2)) {
					min = Math.pow(2 * n - y - b, 2) + Math.pow(x - a, 2);
				}
				//왼쪽 원쿠션
				if (min > Math.pow(x + a, 2) + Math.pow(y - b, 2)) {
					min = Math.pow(x + a, 2) + Math.pow(y - b, 2);
				}
				//아래 원쿠션
				if (min > Math.pow(y + b, 2) + Math.pow(x - a, 2)) {
					min = Math.pow(y + b, 2) + Math.pow(x - a, 2);
				}
				//오른쪽 원쿠션
				if (min > Math.pow(2 * m - x - a, 2) + Math.pow(y - b, 2)) {
					min = Math.pow(2 * m - x - a, 2) + Math.pow(y - b, 2);
				}
            }
            result.add((int)min);
        }
        return result.stream().mapToInt(x->x).toArray();
    }
}
