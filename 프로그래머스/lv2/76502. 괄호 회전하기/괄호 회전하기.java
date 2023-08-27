import java.util.*;
class Solution {
    public int solution(String s) {
        int answer = 0;
        for(int i = 0;i<s.length();i++){
        	Stack<Integer>stack = new Stack<>();
            int j;
            for(j = 0;j<s.length();j++){
                if(s.charAt((i+j)%s.length())==']') {
                	if(stack.size()==0||stack.pop()!=2) {
                		break;
                	}
                }else if(s.charAt((i+j)%s.length())=='}') {
                	if(stack.size()==0||stack.pop()!=1) {
                		break;
                	}
                }else if(s.charAt((i+j)%s.length())==')') {
                	if(stack.size()==0||stack.pop()!=0) {
                		break;
                	}
                }else if(s.charAt((i+j)%s.length())=='(') {
                	stack.add(0);
                }else if(s.charAt((i+j)%s.length())=='{') {
                	stack.add(1);
                }else if(s.charAt((i+j)%s.length())=='[') {
                	stack.add(2);
                }
            }
            if(j==s.length()&&stack.size()==0)
            	answer++;
        }
        return answer;
    }
}