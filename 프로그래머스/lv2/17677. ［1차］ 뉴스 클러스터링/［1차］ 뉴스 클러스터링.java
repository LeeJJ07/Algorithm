import java.util.HashMap;

class Solution {
    public int solution(String str1, String str2) {
        
        int num1 = 0; // str1의 개수
		int num2 = 0; // str2의 개수
		int num3 = 0; // 교집합 개수
		str1 = str1.toLowerCase();
		str2 = str2.toLowerCase();
		HashMap<String,Integer> set1 = new HashMap<>(); // str1 집합

		for (int i = 0; i < str1.length() - 1; i++) {
			String str = str1.substring(i, i + 2);
			boolean check = true;
			for (int j = 0; j < str.length(); j++) { // 문자 확인
				if (str.charAt(j) < 'a' || str.charAt(j) > 'z') {
					check = false;
				}
			}
			if (!check)
				continue;
			num1++;
			set1.put(str, set1.getOrDefault(str, 0)+1);
		}
		for (int i = 0; i < str2.length() - 1; i++) {
			String str = str2.substring(i, i + 2);
			boolean check = true;
			for (int j = 0; j < str.length(); j++) { // 문자 확인
				if (str.charAt(j) < 'a' || str.charAt(j) > 'z') {
					check = false;
				}
			}
			if (!check)
				continue;
			num2++;
			if(set1.containsKey(str)&&set1.get(str)!=0) {
				num3++;
				set1.put(str, set1.get(str)-1);
			}
		}
		if(num1==0&&num2==0)
			return 65536;
		double val = (double)num3 / (num1 + num2 - num3);

		int answer = (int) (val * 65536);
		return answer;
    }
}