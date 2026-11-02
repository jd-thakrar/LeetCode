class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> ans;
        ans.push_back(points[0]);
        int count = 1;
        for(int i = 1; i < points.size(); i++){
            if(ans.back()[1] >= points[i][0]){
                ans.back()[1] = min(ans.back()[1], points[i][1]);
            }else{
                ans.push_back(points[i]);
                count++;
            }
        }
        return count;
    }
};