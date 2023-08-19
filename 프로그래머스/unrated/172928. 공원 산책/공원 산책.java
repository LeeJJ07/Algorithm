class Solution {
    public int[] solution(String[] park, String[] routes) {
        int N = park.length;
        int M = park[0].length();
        int [][]map = new int[N][M];
        int x = 0; 
        int y = 0;
        for(int i = 0; i<N;i++){
            for(int j = 0;j<M;j++){
                if(park[i].charAt(j)=='S'){
                    map[i][j] = 1;
                    x = i;
                    y = j;
                }
                else if(park[i].charAt(j)=='O'){
                    map[i][j] = 0;
                }
                else if(park[i].charAt(j)=='X'){
                    map[i][j] = -1;
                }
            }
        }
        for(int i = 0; i< routes.length;i++){
            String[]spl = routes[i].split(" ");
            int vtx = x;
            int vty = y;
            int []move = new int[2];
            if(spl[0].compareTo("E")==0){
                move[0] = 0;
                move[1] = 1;
            }
            else if(spl[0].compareTo("W")==0){
                move[0] = 0;
                move[1] = -1;
            }
            else if(spl[0].compareTo("S")==0){
                move[0] = 1;
                move[1] = 0;
            }
            else if(spl[0].compareTo("N")==0){
                move[0] = -1;
                move[1] = 0;
            }
            int j;
            for(j = 0;j<Integer.parseInt(spl[1]);j++){
                vtx+=move[0];
                vty+=move[1];
                if(vtx>=N || vty>=M || vtx<0 || vty<0)
                    break;
                if(map[vtx][vty]==-1)
                    break;
            }
            if(j==Integer.parseInt(spl[1])){
                x = vtx;
                y = vty;
            }
        }
        
        int[] answer = {x, y};
        return answer;
    }
}