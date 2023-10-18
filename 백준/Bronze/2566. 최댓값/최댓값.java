import java.util.Scanner;
class Main{
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int max = -1;
		int x= -1, y= -1;
		for(int i = 0;i<9;i++) {
			for(int j = 0;j<9;j++) {
				int num =sc.nextInt();
				if(max<num) {
					x = i+1;
					y = j+1;
					max = num;
				}
			}
		}
		System.out.printf("%d\n%d %d",max,x,y);
	}
}