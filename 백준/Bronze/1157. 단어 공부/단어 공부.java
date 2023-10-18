import java.util.Scanner;
class Main{
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		str = str.toUpperCase();
		int[]check = new int[26];
		for(int i = 0;i<str.length();i++) {
			char c = str.charAt(i);
			check[c-'A']++;
		}
		int max = 0;
		char maxAl = '0';
		boolean maxNum = false;
		for(int i = 0;i<26;i++) {
			if(check[i]>max) {
				max = check[i];
				maxAl = (char)(i+'A');
				maxNum = false;
			}else if(check[i]==max) {
				maxNum = true;
			}
		}
		if(maxNum) {
			System.out.println("?");
		}else {
			System.out.println(maxAl);
		}
	}
}