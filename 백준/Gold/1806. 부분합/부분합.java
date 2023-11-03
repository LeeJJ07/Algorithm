import java.util.Scanner;

class Main
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int S = sc.nextInt();
		int []arr = new int[N];
		for(int i = 0;i<arr.length;i++)
			arr[i] = sc.nextInt();
		int start = 0, end = 0;
		int result = N+1;
		int sum = 0;
		while(end<=N) {
			
			if(sum<S) {
				if(end>=N)
					break;
				sum+=arr[end++];
			}else {
				if(result>end-start)
					result = end-start;
				sum-=arr[start++];
			}
			if(start>end) {
				break;
			}
		}
		if(result == N+1)
			System.out.println(0);
		else
			System.out.println(result);
	}
}