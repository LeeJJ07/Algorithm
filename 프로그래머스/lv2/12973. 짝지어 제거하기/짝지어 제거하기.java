import java.util.*;
class Solution
{
    public int solution(String s)
    {
        char a = s.charAt(0);
        
        Stack<Character> stack = new Stack<Character>();
        for(int i = 0;i<s.length();i++) {
        	if(stack.size()==0) {
        		stack.add(s.charAt(i));
        	}else {
        		if(stack.peek()==s.charAt(i)) {
        			stack.pop();
        		}else {
        			stack.add(s.charAt(i));
        		}
        	}
        }
        if(stack.size()==0)
        	return 1;
        else
        	return 0;
    }
}