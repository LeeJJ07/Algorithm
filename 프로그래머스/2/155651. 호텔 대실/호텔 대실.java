import java.util.*;
class Solution {
    public static class Node{
		int start;
		int end;
		Node(int s, int e){
			this.start = s;
			this.end = e;
		}
	}
    public int solution(String[][] book_time) {
        Node[] bt = new Node[book_time.length];
		for(int i = 0;i<book_time.length;i++) {
			
			int s = Integer.parseInt(book_time[i][0].substring(0, 2))*60 +
					Integer.parseInt(book_time[i][0].substring(3));
			int e = Integer.parseInt(book_time[i][1].substring(0, 2))*60 +
					Integer.parseInt(book_time[i][1].substring(3));
			bt[i] = new Node(s,e);
		}
		Arrays.sort(bt,new Comparator<Node>() {
			@Override
			public int compare(Node o1, Node o2) {
				if(o1.start<o2.start)
					return -1;
				else
					return 1;
			}
		});
		ArrayList<ArrayList<Node>>arr = new ArrayList<>();
		for(int i = 0;i<bt.length;i++) {
			if(arr.isEmpty()) {
				ArrayList<Node>a = new ArrayList<Node>();
				a.add(bt[i]);
				arr.add(a);
			}else {
				int j;
				for(j = 0;j<arr.size();j++) {
					if(arr.get(j).get(arr.get(j).size()-1).end+10<=bt[i].start) {
						arr.get(j).add(bt[i]);
						break;
					}
				}
				if(j==arr.size()) {
					ArrayList<Node>a = new ArrayList<Node>();
					a.add(bt[i]);
					arr.add(a);
				}
			}
		}
        return arr.size();
    }
}