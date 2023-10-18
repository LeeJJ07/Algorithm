import java.util.Scanner;
class Main{
	
	public static void main(String args[]){
		
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int m = sc.nextInt();
		int t = 0;
		if(h*60 + m >= 45) {
			t = h*60 + m - 45;
			System.out.println(t/60 + " " + t%60);
		}else {
			t = h*60 + m - 45 + 60*24;
			System.out.println(t/60 + " " + t%60);
		}
	}
}