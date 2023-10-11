import java.util.*;
class Solution {
    public int[] solution(String s) {
        s = s.substring(2,s.length()-2);
        String[]st = s.split("\\},\\{");
        String [][]str = new String[st.length][];
        for(int i = 0;i<st.length;i++)
        	str[i] = st[i].split(",");
        
        Arrays.sort(str,new Comparator<String[]>() {
        	@Override
        	public int compare(String[] o1, String[] o2) {
        		if(o1.length<o2.length)
        			return -1;
        		else
        			return 1;
        	}
		});
        ArrayList<Integer>arr = new ArrayList<Integer>();
        Set <String> set = new HashSet<String>();
       	for(int i = 0;i<str.length;i++) {
       		for(int j = 0;j<str[i].length;j++) {
       			if(!set.contains(str[i][j])) {
       				arr.add(Integer.parseInt(str[i][j]));
       				set.add(str[i][j]);
       				break;
       			}
       		}
       	}
        return arr.stream().mapToInt(x->x).toArray();
    }
}