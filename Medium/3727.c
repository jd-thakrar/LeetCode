class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        int l = 0, k = 1, r = nums.size() - 1;
        long long sum = 0;
        while (l <= r) {
            long long dig = 0;
            if (k % 2 != 0) {
                dig = (long long)nums[r] * nums[r];
                sum += dig;
                r--;

            } else {
                dig = (long long)nums[l] * nums[l];
                sum -= dig;
                l++;
            }
            k++;
        }
        return sum;
    }
};

//https://leetcode.com/problems/maximum-alternating-sum-of-squares/solutions/8570261/3727-maximum-alternating-sum-of-squares-3w7to