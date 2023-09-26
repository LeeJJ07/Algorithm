class Solution {
    public String solution(String new_id) {
        new_id = new_id.toLowerCase();
        for(int i = 0;i<new_id.length();i++) {
        	if(new_id.charAt(i)<='z'&&new_id.charAt(i)>='a')
        		continue;
        	else if(new_id.charAt(i)=='.'||
        			new_id.charAt(i)=='_'||
        			new_id.charAt(i)=='-')
        		continue;
        	else if(new_id.charAt(i)<='9'&&new_id.charAt(i)>='0')
        		continue;
        	new_id = new_id.substring(0,i)+ new_id.substring(i+1);
        	i--;
        }
        
        for(int i = 0;i<new_id.length();i++) {
        	if(new_id.charAt(i)=='.') {
        		for(int j = i+1;j<new_id.length();j++) {
        			if(new_id.charAt(j)=='.') {
        				new_id = new_id.substring(0,j) + new_id.substring(j+1);
        				j--;
        			}else {
        				break;
        			}
        		}
        	}
        }
		
		if (new_id.length()!=0&&new_id.charAt(0) == '.')
			new_id = new_id.substring(1);
		if (new_id.length()!=0&&new_id.charAt(new_id.length() - 1) == '.')
			new_id = new_id.substring(0, new_id.length() - 1);
        if(new_id.length()==0)
        	new_id = "a";
        if(new_id.length()>=16)
        	new_id = new_id.substring(0,15);
        if(new_id.charAt(new_id.length()-1)=='.')
        	new_id = new_id.substring(0,new_id.length()-1);
        
        if(new_id.length()<=2) {
        	int len = new_id.length();
        	for(int i = 0;i<3-len;i++) {
        		new_id = new_id.concat(String.valueOf(new_id.charAt(new_id.length()-1)));
        	}
        }
        return new_id;
    }
}