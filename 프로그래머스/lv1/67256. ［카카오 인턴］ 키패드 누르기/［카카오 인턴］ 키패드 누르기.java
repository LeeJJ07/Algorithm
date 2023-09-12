class Solution {
    static class hd{
        int x;
        int y;
        hd(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    public String solution(int[] numbers, String hand) {
        StringBuilder sb = new StringBuilder();
        hd left = new hd(3,0);
        hd right = new hd(3,2);
        hd []keypad = new hd[12];
        for(int i = 0;i<12;i++){
        	keypad[i] = new hd(i/3,i%3);
        }
        
        for(int i = 0;i<numbers.length;i++){
            if(numbers[i]==2 || numbers[i]==5 
            		|| numbers[i]==8 ||numbers[i]==0){
                if(numbers[i]==0)
                    numbers[i] = 11;
                if(Math.abs(keypad[numbers[i]-1].x - left.x)+Math.abs(keypad[numbers[i]-1].y - left.y)>
                  Math.abs(keypad[numbers[i]-1].x - right.x)+Math.abs(keypad[numbers[i]-1].y - right.y)){
                    right = keypad[numbers[i]-1];
                    sb.append("R");
                }else if(Math.abs(keypad[numbers[i]-1].x - left.x)+Math.abs(keypad[numbers[i]-1].y - left.y)<
                  Math.abs(keypad[numbers[i]-1].x - right.x)+Math.abs(keypad[numbers[i]-1].y - right.y)){
                    left = keypad[numbers[i]-1];
                    sb.append("L");
                }else{
                    if(hand.equals("right")){
                        right = keypad[numbers[i]-1];
                        sb.append("R");
                    }else{
                        left = keypad[numbers[i]-1];
                        sb.append("L");
                    }
                }
            }else if(numbers[i]==1 || numbers[i]==4 ||numbers[i]==7){
     
                left = keypad[numbers[i]-1];
                sb.append("L");
            }else{
                right = keypad[numbers[i]-1];
                sb.append("R");
            }
        }
        
        return sb.toString();
    }
}