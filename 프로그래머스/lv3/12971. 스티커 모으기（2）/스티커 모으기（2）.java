import java.util.Arrays;
class Solution {
	
	public int solution(int sticker[]) {
        if(sticker.length==1)
			return sticker[0];
		int []check1 = new int[sticker.length];

		check1[0] = sticker[0];
		check1[1] = sticker[1];

		for(int i = 2;i<sticker.length-1;i++) {
			if(check1[i]<sticker[i]+check1[i-2]) {
				check1[i] = sticker[i]+check1[i-2];
			}
			if(i-3>=0&&check1[i]<sticker[i]+check1[i-3]) {
				check1[i] = sticker[i]+check1[i-3];
			}
		}
		Arrays.sort(check1);
		int max = check1[check1.length-1];
		int []check2 = new int[sticker.length];
		check2[1] = sticker[1];
		for(int i = 2;i<sticker.length;i++) {
			if(check2[i]<sticker[i]+check2[i-2]) {
				check2[i] = sticker[i]+check2[i-2];
			}
			if(i-3>=0&&check2[i]<sticker[i]+check2[i-3]) {
				check2[i] = sticker[i]+check2[i-3];
			}
		}
		Arrays.sort(check2);
		if(max<check2[check2.length-1])
			max = check2[check2.length-1];
        return max;
    }
}