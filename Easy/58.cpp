class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int index;
        int len = 0;
        for(int i = n-1 ; i>=0; i--){
            index = i;
            if(s[i] != ' '){
                break;
            }
        }
        for(int i = index; i>=0 ; i--){
            
            if(s[i] == ' '){
                break;
            }  
            len++;  
        }
        return len;
    }
};