
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            int count = 1, mx = INT_MIN;
            sort(nums.begin(), nums.end());

            for (int i = 1; i < n; i++) {
                if (nums[i - 1] == nums[i] - 1) {
                    count++;
                } else if (nums[i - 1] == nums[i]) {
                   
                } else {
                    count = 1;
                }
                mx = max(count, mx);
            }

            return mx;
        }
    }
};