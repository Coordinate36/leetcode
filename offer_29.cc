class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) {
            return ans;
        }
        int m = 0, n = 0;
        while (m < matrix.size() / 2 && n < matrix[0].size() / 2) {
            int row_limit = matrix.size() - m;
            int col_limit = matrix[0].size() - n;
            for (int j = n; j < col_limit; ++j) {
                ans.push_back(matrix[m][j]);
            }
            for (int i = m+1; i < row_limit; ++i) {
                ans.push_back(matrix[i][col_limit-1]);
            }
            for (int j = col_limit-2; j >= n; --j) {
                ans.push_back(matrix[row_limit-1][j]);
            }
            for (int i = row_limit-2; i > m; --i) {
                ans.push_back(matrix[i][n]);
            }
            ++m;
            ++n;
        }
        if (matrix.size() > matrix[0].size() && (matrix[0].size() & 1)) {
            for (int i = m; i < matrix.size()-m; ++i) {
                ans.push_back(matrix[i][n]);
            }
        } else if (matrix.size() <= matrix[0].size() && (matrix.size() & 1)) {
            for (int j = n; j < matrix[0].size()-n; ++j) {
                ans.push_back(matrix[m][j]);
            }
        }
        return ans;
    }
};