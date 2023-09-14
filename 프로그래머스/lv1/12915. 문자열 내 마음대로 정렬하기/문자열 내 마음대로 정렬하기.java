import java.util.*;
class Solution {
    public String[] solution(String[] strings, int n) {
        Arrays.sort(strings, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				// TODO Auto-generated method stub
				if(o1.charAt(n)>o2.charAt(n))
					return 1;
				else if(o1.charAt(n)<o2.charAt(n))
					return -1;
				else{
                    if(o1.compareTo(o2)>0)
                        return 1;
                    else
                        return -1;
                }
			}
		});
		
        return strings;
    }
}