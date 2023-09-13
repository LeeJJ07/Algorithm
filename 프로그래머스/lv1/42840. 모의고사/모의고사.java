import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
       
        int[][]person = {
            {1,2,3,4,5},
            {2,1,2,3,2,4,2,5},
            {3,3,1,1,2,2,4,4,5,5}
        };
        
        
        int[] answer = new int[3];
        int max = 0;
        for(int i = 0;i<3;i++){
            int count = 0;
            for(int j = 0;j<answers.length;j++){
                if(person[i][j%person[i].length]==answers[j])
                    count++;
            }
            answer[i] = count;
            if(count>max)
                max = count;
        }
        ArrayList<Integer>result = new ArrayList<>();
        for(int i =0;i<3;i++)
            if(answer[i]==max)
                result.add(i+1);
        return result.stream().mapToInt(x->x).toArray();
    }
}