class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    ans.push_back({1});
                } 
                else if(i == j){
                    ans.back().push_back(1);
                }
                else {
                    int fel = ans[i - 1][j - 1];
                    int sel = ans[i - 1][j];
                    ans.back().push_back(fel + sel);
                }
            }
        }

        return ans[rowIndex];
    }
};