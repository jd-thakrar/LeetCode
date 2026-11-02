class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        int n = coins.size();
        for(int i = 0; i<amount+1; i++){
            int mi = INT_MAX;
            if(i == 0){
                dp[0] = 0;
                continue;
        }
            for(int j = 0; j<n;j++){
                if(i-coins[j]>=0)
                    mi = min(mi , dp[i-coins[j]]);
            } 
            if(mi == INT_MAX){
                continue;
            }
            dp[i] = mi +1;
        }
        return dp[amount]<INT_MAX?dp[amount]:-1;
    }
};