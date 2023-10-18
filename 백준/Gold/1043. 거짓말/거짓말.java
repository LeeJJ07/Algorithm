import java.util.Scanner;
class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		boolean []p = new boolean[N];
		int K = sc.nextInt();
		for(int i = 0;i<K;i++) {
			p[sc.nextInt()-1] = true;
		}
		int[][]party = new int[M][];
		for(int i = 0;i<M;i++) {
			int n = sc.nextInt();
			party[i] = new int[n];
			for(int j = 0;j<n;j++) {
				party[i][j] = sc.nextInt();
			}
		}
		
		for (int q = 0; q < M; q++) {
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < party[i].length; j++) {
					if (p[party[i][j] - 1]) {
						for (int k = 0; k < party[i].length; k++) {
							p[party[i][k] - 1] = true;
						}
						break;
					}
				}
			}
		}
		int result = 0;
		for(int i = 0;i<M;i++) {
			int j;
			for(j = 0;j<party[i].length;j++) {
				if(p[party[i][j]-1]) {
					break;
				}
			}
			if(j==party[i].length)
				result++;
		}
		System.out.println(result);
	}
}