//T.C. : O(n^2)
//O.C. : O(1)

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool res;

        for (int c = 1; c < 5; c++) {//O(1)
            bool equal = true;
            for (int i = 0; i < n; i++) {//O(n^2)
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] != target[i][j]) {
                        equal = false;
                    }
                }
                if (!equal) {
                    break;
                }
            }
            if (equal) {
                res = true;
            } else {
                if (c == 4) {
                    res = false;
                }
                for (int i = 0; i < n; i++) {//O(n^2)
                    for (int j = i + 1; j < n; j++) {
                        swap(mat[i][j], mat[j][i]);
                    }
                }
                for (int i = 0; i < n; i++) {//O(n)
                    reverse(mat[i].begin(), mat[i].end());
                }
            }
        }
        return res;
    }
};

