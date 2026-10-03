class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        int m = knowledge.size();
        string str;
        string ans;

        unordered_map<string,string> mp;
        
        for(int i = 0; i<m; i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }


        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                i++;
                while (s[i] != ')') {
                    str += s[i];
                    i++;
                }
                bool get = false;
                if (mp.find(str) != mp.end()) {
                    ans += mp[str];
                    get = true;
                } 
                if(get == false){
                    ans += '?';
                }
                str.clear();
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};