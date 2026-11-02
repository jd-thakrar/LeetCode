
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;

        for(string word : strs){
            string key = word;
            sort(key.begin(), key.end());

            mp[key].push_back(word);
        }   

        vector<vector<string>> ans;
        for(auto &word : mp){
            ans.push_back(word.second);
        }

        return ans;
    }
};