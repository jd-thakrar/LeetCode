class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size(), m = accounts[0].size();
        int mx = INT_MIN, sum = 0;

        for(int i = 0; i<n; i++){
            mx = max(mx, sum);
            sum = 0;
            for(int j = 0; j<m; j++){
                sum += accounts[i][j]; 
            }
            if(n == 1){
                return sum;
            }
        }
        return mx;
    }
};