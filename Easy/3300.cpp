class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size(), sum = 0, ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            sum = 0;
            while (num > 0) {
                int digit = num % 10;
                sum += digit;
                num = num / 10;
            }
            ans = min(sum, ans);
        }
        return ans;
    }
};

