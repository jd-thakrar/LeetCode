class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), tp = n * n;
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[grid[i][j]]++;
            }
        }

        for (int i = 1; i <= tp; i++) {
            if (mp[i] == 2) {
                ans.push_back(i);
                break;
            }
        }

        for (int i = 1; i <= tp; i++) {
            if (mp[i] == 0) {
                ans.push_back(i);
                break;
            }
        }

        return ans;
    }
};