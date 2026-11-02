class Solution {
public:
    int rob(vector<int>& nums) {
        int i = 2, n = nums.size(),cur;

        if(n == 1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }

        int prev1 = nums[0];
        int prev2 = max(nums[0],nums[1]);

        while(i<n-1){
            cur = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = cur;
            i++;
        }
        int prev3 = prev2;
        prev1 = nums[1];
        prev2 = max(nums[1],nums[2]);
        i = 3;
        while(i<n){
            cur = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = cur;
            i++;
        }

        return max(prev2, prev3);
    }
};