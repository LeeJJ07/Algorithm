import java.util.Scanner;
class Main{
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int [][]map = new int[100][100];
		for(int i = 0;i<N;i++) {
			int s = sc.nextInt();
			int e = sc.nextInt();
			for(int j = 0; j<10;j++) {
				for(int k = 0;k<10;k++) {
					map[j+s][k+e]++;
				}
			}
		}
		int count = 0;
		for(int i = 0;i<100;i++) {
			for(int j = 0;j<100;j++) {
				if(map[i][j]==0)
					count++;
			}
		}
		System.out.println(10000-count);
	}
}