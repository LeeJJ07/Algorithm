import java.util.*;
class Solution {
    static class Node{
		String name;
		double t;
		Node(String nm, double t){
			this.name = nm;
			this.t = t;
		}
	}
    public int[] solution(int[] fees, String[] records) {
        ArrayList<Node> arr = new ArrayList<Node>();
		TreeMap<String, Double> result = new TreeMap<String, Double>();
		for(int i = 0;i<records.length;i++) {
			String name = records[i].substring(6, 10);
		    double t = Double.parseDouble(records[i].substring(0,2)) * 60
					+ Double.parseDouble(records[i].substring(3, 5));
			if(records[i].substring(11).equals("IN")) {
				arr.add(new Node(name,t));
			}else {
				for(int j = 0;j<arr.size();j++) {
					if(arr.get(j).name.equals(name)) {
						result.put(name, result.getOrDefault(name, 0.0)+(t-arr.get(j).t));
						arr.remove(j);
						break;
					}
				}
			}
		}
		for(int i = 0;i<arr.size();i++) {
			result.put(arr.get(i).name, result.getOrDefault(arr.get(i).name, 0.0)+(23*60 +59-arr.get(i).t));
		}
        int[] answer = new int[result.size()];
        Object[] mapKey = result.keySet().toArray();
        Arrays.sort(mapKey);
        int idx = 0;
        for (String key : result.keySet()) {
        	if(result.get(key)>fees[0]) {
        		answer[idx++] = fees[1] + (int)Math.ceil((result.get(key)-fees[0])/fees[2]) * fees[3];
        	}else {
        		answer[idx++] = fees[1];
        	}
        }
        return answer;
    }
}