class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int count = 0;
        for(int i = 1 ; i < intervals.size() ; i++){
           
            if(ans.back()[1] > intervals[i][0] ){
                ans.back()[1]=min(ans.back()[1], intervals[i][1]);
                count++;
            }
            else
                ans.push_back(intervals[i]);
            }
        return count;
    }
};

//https://leetcode.com/problems/non-overlapping-intervals/solutions/8306613/435-non-overlapping-intervals-by-thakrar-ni83