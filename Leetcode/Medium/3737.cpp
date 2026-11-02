class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), count = 0, sum;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = i; j < n; j++) {
                if (target == nums[j]) {
                    sum++;
                }
                double m = (j - i + 1) / 2;
                if (sum > m) {
                    count++;
                }
            }
        }
        return count;
    }
};