class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n = s.size();
        string one = "", two = "", three = "";
        for(int i = 0; i<n; i++){
            if(s[i] == y){
                one += s[i];
            }else if(s[i] != x && s[i] != y){
                two += s[i];
            }else{
                three += s[i];
            }
        }   
        return one + two + three;
    }
};