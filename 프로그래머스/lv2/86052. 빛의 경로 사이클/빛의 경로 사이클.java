import java.util.*;
class Solution {
    static int[]mx = {0,1,0,-1};
    static int[]my = {1,0,-1,0};
    public int[] solution(String[] grid) {
        ArrayList <Integer> result = new ArrayList<>();
        int [][][]map = new int[grid.length][grid[0].length()][4];
        // s = 0, l = 1, r = 2
        // 0 왼쪽, 1 아래쪽, 2 오른쪽, 3 위쪽 에서 들어오는 빛;
        for(int i = 0;i<grid.length;i++){
            for(int j = 0;j<grid[i].length();j++){
                for(int k = 0;k<4;k++){
                    if(map[i][j][k]==0){
                        int sx = i; int sy = j; int sk = k;
                        int count = 0;
                        while(true){
                            if(map[sx][sy][sk]==1)
                                break;
                            count++;
                            map[sx][sy][sk] = 1;
                            if(grid[sx].charAt(sy)=='S'){
                                sx += mx[sk];
                                sy += my[sk];
                            }else if(grid[sx].charAt(sy)=='L'){
                                sk+=1;
                                if(sk==4)
                                    sk = 0;
                                sx += mx[sk];
                                sy += my[sk];
                            }else if(grid[sx].charAt(sy)=='R'){
                                sk-=1;
                                if(sk==-1)
                                    sk = 3;
                                sx += mx[sk];
                                sy += my[sk];
                            }
                            if(sx<0){
                                sx = grid.length-1;
                            }if(sy<0){
                                sy = grid[sx].length()-1;
                            }if(sx>=grid.length){
                                sx = 0;
                            }if(sy>=grid[sx].length()){
                                sy = 0;
                            }
                        }
                        result.add(count);
                    }
                }
            }
        }
        Collections.sort(result);
        return result.stream().mapToInt(x->x).toArray();
    }
}