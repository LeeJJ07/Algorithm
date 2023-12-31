import java.util.Stack;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer>stack = new Stack<Integer>();
        for(int i = 0;i<moves.length;i++) {
        	for(int j = 0;j<board.length;j++) {
        		if(board[j][moves[i]-1]==0)
        			continue;
        		if(stack.isEmpty())
        			stack.add(board[j][moves[i]-1]);
        		else {
        			if(stack.peek()==board[j][moves[i]-1]) {
        				stack.pop();
        				answer+=2;
        			}else {
        				stack.add(board[j][moves[i]-1]);
        			}
        		}
        		board[j][moves[i]-1] = 0;
        		break;
        	}
        }
        return answer;
    }
}