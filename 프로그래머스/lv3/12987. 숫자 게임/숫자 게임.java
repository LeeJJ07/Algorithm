import java.util.Arrays;
class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        Arrays.sort(A);
        Arrays.sort(B);
        int idxA = A.length-1;
        int idxB = B.length-1;
        while(idxA>=0) {
        	if(A[idxA]>=B[idxB]) {
        		idxA--;
        	}else {
        		idxA--;
        		idxB--;
        		answer++;
        	}
        }
        return answer;
    }
}