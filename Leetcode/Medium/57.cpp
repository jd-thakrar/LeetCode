class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool inserted = false;

        if (intervals.size() == 0) {
            return {newInterval};
        }
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                if (!inserted) {
                    ans.push_back(newInterval);
                    inserted = true;
                }
                ans.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        if (!inserted) {
            ans.push_back(newInterval);
        }

        return ans;
    }
};

//https://leetcode.com/problems/insert-interval/solutions/8304572/57-insert-interval-by-thakrar_jeet-1g7k