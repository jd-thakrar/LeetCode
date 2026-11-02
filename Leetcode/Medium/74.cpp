class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size(), m = matrix.size(), te = n * m, l = 0,
            r = te - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }
};

//https://leetcode.com/problems/search-a-2d-matrix/solutions/8299302/74-search-a-2d-matrix-using-binary-searc-emp9