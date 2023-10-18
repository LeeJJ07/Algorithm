import java.util.Scanner;
class Main{
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sc.nextLine();
		int result = 0;
		for(int i = 0;i<N;i++) {
			String str = sc.nextLine();
			if(str.length()==1) {
				result++;
				continue;
			}
			boolean []check = new boolean[26];
			check[str.charAt(0)-'a'] = true;
			int j;
			for(j = 0;j<str.length()-1;j++) {
				if(str.charAt(j)!=str.charAt(j+1)) {
					if(check[str.charAt(j+1)-'a'])
						break;
					check[str.charAt(j+1)-'a'] = true;
				}
			}
			if(j!=str.length()-1)
				continue;
			result++;
		}
		System.out.println(result);
	}
}