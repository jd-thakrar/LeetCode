class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m-k+1, vector<int>(n-k+1, 0));


        int count = 0;

        for(int i = 0 ; i<=m-k ; i++){
            for(int j=0; j<=n-k; j++){

                set<int> arr;
                
                for(int a=i; a<=i+k-1; a++){
                    for(int b = j; b<=j+k-1; b++){
                        arr.insert(grid[a][b]);
                    }
                }

                 if (arr.size() == 1) {
                    continue;
                }
                int min_diff = INT_MAX;
                auto prev = arr.begin();
                auto cur = next(prev);
                
                while(cur != arr.end()){
                    min_diff =  min(min_diff, *cur-*prev);
                    prev = cur;
                    cur++;
                }

                result[i][j] = min_diff;

            }
        }

        return result;
    }

};