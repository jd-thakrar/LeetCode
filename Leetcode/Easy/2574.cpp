class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size(), sum = 0,fsum;
        vector<int> ans;
        for(int i = 0; i<n;i++){
            sum += nums[i];
        }
        fsum=sum;
        for(int i = 0; i<n;i++){
            sum = sum - nums[i];
            ans.push_back(sum);
        }

        for(int i = n-1; i>=0;i--){
            fsum = fsum-nums[i];
            int dig = fsum-ans[i];
            
            ans[i] = abs(dig);
        }

        return ans;
        
    }
};