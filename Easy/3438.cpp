class Solution {
public:
    string findValidPair(string s) {
        map<int, int> mp;
        int n = s.size();
        for(int i = 0; i<n; i++){
            int digit = s[i] - '0';

            mp[digit]++;
        }
        
        for(int i = 1; i<n; i++){
            int a = s[i-1] - '0';
            int b = s[i] - '0';

            if(a!=b && mp[a] == a && mp[b] == b){
                int ans = a*10 + b;
                return to_string(ans);
            }
        }
        return "";
    }
};