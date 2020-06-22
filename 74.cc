class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int low = 0, high = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (matrix[mid][0] > target) {
                high = mid - 1;
            } else if (matrix[mid][right] < target) {
                low = mid + 1;
            } else {
                break;
            }
        }
        auto& row = matrix[mid];
        if (row[0] > target || row[right] < target) {
            return false;
        }
        while (left <= right) {
            mid = (left + right) >> 1;
            if (row[mid] > target) {
                right = mid - 1;
            } else if (row[mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};