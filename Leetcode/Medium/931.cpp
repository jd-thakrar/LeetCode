class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        
        vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0){
                    dp[i][j] = matrix[i][j];
                    continue;
                }
                int fir = j - 1 < 0 ? INT_MAX : dp[i - 1][j - 1];
                int sec = dp[i - 1][j];
                int lst = j + 1 > n - 1 ? INT_MAX : dp[i - 1][j + 1];

                dp[i][j] = matrix[i][j] + min({fir, sec, lst});
            }
        }

        int minp = dp[n - 1][0];
        for (int i = 1; i < n; i++) {
            minp = min(minp, dp[n - 1][i]);
        }

        return minp;
    }
};