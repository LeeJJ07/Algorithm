import java.util.Arrays;
import java.util.Scanner;
class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[]building = new int[N];
		int []result = new int[N];
		for(int i = 0;i<N;i++)
			building[i] = sc.nextInt();
		for(int i = 0;i<N-1;i++) {
			double m = -2000000000;
			for(int j = i+1;j<N;j++) {
				if(m<(double)(building[j]-building[i])/(j-i)) {
					m = (double)(building[j]-building[i])/(j-i);
					result[i]++;
				}
			}
		}
		for(int i = N-1;i>0;i--) {
			double m = 2000000000;
			for(int j = i-1; j>=0;j--) {
				if(m>(double)(building[j]-building[i])/(j-i)) {
					m=(double)(building[j]-building[i])/(j-i);
					result[i]++;
				}
			}
		}
		Arrays.sort(result);
		System.out.println(result[N-1]);
	}
}