
//Using the Unorderd Map method
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




//Using the Set method
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), expSum = 0, actSum = 0, a;
        vector<int> ans;
        unordered_set<int> s;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actSum += grid[i][j];
                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        expSum = (n * n) * (n * n + 1) / 2;
        int b = expSum - actSum + a;
        ans.push_back(b);
        return ans;
    }
};