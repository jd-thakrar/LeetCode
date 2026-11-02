class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, pair<bool,bool>> m;
        unordered_map<char, bool> s;

        for(char c : word){
            if(islower(c)){
                if(m[c].second){
                    m[c].first = false;
                    s[c] = true;
                }
                else if(s[c] == false )
                    m[c].first = true;
                
            }
            else{
                char lw = tolower(c);
                if(m[lw].first){
                    m[lw].second=true;
                }
                else{
                    s[lw] =true;
                }
            }
        }   
        int count = 0;
        for(auto const& [key, val] : m){
            if(val.first && val.second && !s[key]){
                count++;
            }
        }
        return count;
    }

};

//https://leetcode.com/problems/count-the-number-of-special-characters-ii/solutions/8296435/3121-count-the-number-of-special-charact-w7mx/