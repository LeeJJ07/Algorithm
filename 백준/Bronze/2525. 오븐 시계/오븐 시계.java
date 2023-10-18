import java.util.Scanner;
class Main{
	
	public static void main(String args[]){
		
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int m = sc.nextInt();
		int t = sc.nextInt();
		t+= 60*h+m;
		if(t>=60*24) {
			t-=60*24;
			System.out.println(t/60 + " " + t%60);
		}else {
			System.out.println(t/60 + " " + t%60);
		}
	}
}