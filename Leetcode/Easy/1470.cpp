class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int tn = n;
        int i = 0;
        vector<int> ans;
        while (i < n) {
            ans.push_back(nums[i]);
            ans.push_back(nums[tn]);

            i++;
            tn++;
        }
        return ans;
    }
};
