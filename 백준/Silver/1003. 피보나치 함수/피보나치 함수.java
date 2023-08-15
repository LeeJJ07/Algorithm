import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main {
	public static class Node{
		int zeroNum = 0;
		int oneNum = 0;
		Node(int ze, int on){
			this.zeroNum = ze;
			this.oneNum = on;
		}
	}
    
    public static void main(String args[]) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        
        Node[]n = new Node[41];
        Node num1 = new Node(1, 0);
        Node num2 = new Node(0, 1);
        n[0] = num1;
        n[1] = num2;
        for(int i = 2;i<41;i++) {
        	Node num = new Node(n[i-2].zeroNum+n[i-1].zeroNum,n[i-2].oneNum+n[i-1].oneNum);
        	n[i] = num;
        }
        for(int i = 0;i<T;i++) {
        	int number = Integer.parseInt(br.readLine());
        	System.out.println(n[number].zeroNum+" "+n[number].oneNum);
        }
       	
    }
    
}