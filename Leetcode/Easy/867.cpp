//Leetcode Solution Link: https://leetcode.com/problems/transpose-matrix/solutions/7681203/simple-transpose-method-by-thakrar_jeet-7fip
//T.C. : O(m * n)
//S.C. : O(m * n)

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i< m ; i++){
            for(int j = 0; j<n; j++){
                res[j][i]=matrix[i][j];
            }
        }
        return res;
    }
};
