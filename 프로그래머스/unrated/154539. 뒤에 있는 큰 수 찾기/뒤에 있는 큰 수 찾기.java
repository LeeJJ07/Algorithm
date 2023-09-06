import java.util.*;
class Solution {
    static class Node{
    	int idx;
    	int number;
    	Node(int idx, int number){
    		this.idx = idx;
    		this.number = number;
    	}
    }
    public static int[] solution(int[] numbers) {
        int []answer = new int[numbers.length];
    	Stack<Node>stk = new Stack<Node>();
    	stk.add(new Node(0,numbers[0]));
    	for(int i = 1;i<numbers.length;i++) {
    		while(stk.size()!=0&&stk.peek().number<numbers[i]) {
    			answer[stk.pop().idx] = numbers[i];
    		}
    		stk.add(new Node(i,numbers[i]));
    	}
    	for(int i = 0 ;i<answer.length;i++) {
    		if(answer[i]==0) {
    			answer[i] = -1;
    		}
    	}
    	return answer;
    }
}