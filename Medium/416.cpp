class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        
        for(int i = 0; i<n ; i++){
            sum+=nums[i];
        }
        if(sum % 2 != 0) return false;
        int mid = sum/2;
        
        vector<vector<bool>> dp(n, vector<bool>(mid+1, false));
        
        for(int i= 0; i<n;i++){
            for(int j=0; j<=mid; j++){
                if(i == 0 ){
                    dp[i][j] = (j==0 || j == nums[i]);
                } else if(i==0 && j!=0){
                    dp[i][j] = false;
               }else if(j==0){
                   dp[i][j]= true;
               }
                else if(nums[i]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }
        }
        
        return dp[n-1][mid];
    }
};