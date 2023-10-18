import java.util.Scanner;
class Main{
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String a = sc.nextLine();
		a = a.replaceAll("c=", "a");
		a = a.replaceAll("c-", "a");
		a = a.replaceAll("dz=", "a");
		a = a.replaceAll("d-", "a");
		a = a.replaceAll("lj", "a");
		a = a.replaceAll("nj", "a");
		a = a.replaceAll("s=", "a");
		a = a.replaceAll("z=", "a");
		
		System.out.println(a.length());
	}
}