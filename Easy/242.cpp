class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count, count2;
        int n = s. size(), m=t.size();
        
        if(n != m) return false;
        for(int i =0; i<n;i++){
            count[s[i]]++;
            count2[t[i]]++;
        }
        
        return count == count2;
        
    }
};