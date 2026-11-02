class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int prev1 = nums[0];
        int prev2 = max(nums[1],nums[0]);
        int i = 2, cur;
        while(i<nums.size()){
            cur = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = cur;
            i++;
        }
        return prev2;
    }
};