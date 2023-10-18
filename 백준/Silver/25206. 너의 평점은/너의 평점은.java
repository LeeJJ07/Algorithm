import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
class Main{
	
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sum = 0;
		double scoreSum=0;
		for(int i = 0;i<20;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String name = st.nextToken();
			double dg = Double.parseDouble(st.nextToken());
			String score = st.nextToken();
			sum += dg;
			if (score.equals("A+")) {
				scoreSum += dg * 4.5;
			} else if (score.equals("A0")) {
				scoreSum += dg * 4.0;
			} else if (score.equals("B+")) {
				scoreSum += dg * 3.5;
			} else if (score.equals("B0")) {
				scoreSum += dg * 3.0;
			} else if (score.equals("C+")) {
				scoreSum += dg * 2.5;
			} else if (score.equals("C0")) {
				scoreSum += dg * 2.0;
			} else if (score.equals("D+")) {
				scoreSum += dg * 1.5;
			} else if (score.equals("D0")) {
				scoreSum += dg * 1.0;
			} else if (score.equals("P")) {
				sum -= dg;
			}
		}
		System.out.printf("%.6f",(double)scoreSum/sum);
	}
}