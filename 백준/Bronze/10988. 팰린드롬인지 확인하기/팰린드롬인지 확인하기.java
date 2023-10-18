import java.util.Scanner;
class Main{
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		StringBuilder sb = new StringBuilder();
		sb.append(str);
		if(sb.reverse().toString().equals(str)) {
			System.out.println(1);
		}else {
			System.out.println(0);
		}
	}
}