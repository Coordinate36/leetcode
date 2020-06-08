class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int x = 0;
        int y = matrix[0].size() - 1;
        while (x < matrix.size() && y >= 0) {
            if (matrix[x][y] > target) {
                --y;
            } else if (matrix[x][y] < target) {
                ++x;
            } else {
                return true;
            }
        }
        return false;
    }
};