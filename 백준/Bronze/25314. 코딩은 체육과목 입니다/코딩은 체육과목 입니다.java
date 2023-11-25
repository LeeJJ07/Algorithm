import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		for(int i = 0;i<(N+3)/4;i++) {
			System.out.print("long ");
		}
		System.out.println("int");
	}
}