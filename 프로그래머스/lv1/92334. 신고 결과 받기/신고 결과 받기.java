import java.util.*;
class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        
        HashSet<String> hashSet = new HashSet<>(Arrays.asList(report));

		String[] resultArr = hashSet.toArray(new String[0]);

		String[][] map = new String[resultArr.length][2];
		for (int i = 0; i < resultArr.length; i++) {
			map[i] = resultArr[i].split(" ");
		}

		HashMap<String, Integer> hash = new HashMap<>();//신고당한 사람과 신고당한 횟수
		for(int i = 0 ;i<map.length;i++) {
			hash.put(map[i][1], hash.getOrDefault(map[i][1], 0)+1);
		}
		
		Set<String>set = new HashSet<String>(); //신고당한 사람 일정 수준 넘어가면 set 에 추가.
		for(int i = 0;i<id_list.length;i++) {
			if(hash.containsKey(id_list[i])) {
				if(hash.get(id_list[i])>=k) {
					set.add(id_list[i]);
				}
			}
		}
		HashMap<String, Integer>hash1 = new HashMap<String, Integer>();
		for(int i = 0;i<map.length;i++) {
			if(set.contains(map[i][1])) {
				hash1.put(map[i][0], hash1.getOrDefault(map[i][0], 0)+1);
			}
		}
		int[] answer = new int[id_list.length];
		for(int i = 0;i<id_list.length;i++) {
			if(hash1.containsKey(id_list[i])) {
				answer[i] = hash1.get(id_list[i]);
			}
		}
		
		return answer;
    }
}