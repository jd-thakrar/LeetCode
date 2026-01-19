class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {

        int best = 0;
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> prefix(rows, vector<int>(cols, 0));

        // here we build the prefix array which consit the sum at each from the
        // top left side of array
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] = (i > 0 ? prefix[i - 1][j] : 0) +
                               (j > 0 ? prefix[i][j - 1] : 0) -
                               (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0) +
                               mat[i][j];
            }
        }

        // lambda function for sum of square
        auto sumSquare = [&](int i, int j, int r2, int c2) {
            int sum = prefix[r2][c2] - (i > 0 ? prefix[i - 1][c2] : 0) -
                      (j > 0 ? prefix[r2][j - 1] : 0) +
                      (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            return sum;
        };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int offset = best; offset < min(rows - i, cols - j);
                     offset++) {
                    int r2 = i + offset;
                    int c2 = j + offset;

                    int sum = sumSquare(i, j, r2, c2);

                    if (sum <= threshold) {
                        best = offset + 1;
                    } else {
                        break;
                    }
                }
            }
        }
        return best;
    }
};


//Refrence: https://www.youtube.com/watch?v=olDXKOSydpg