#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return vector<int>();
        }
        int height = matrix.size();
        int len = matrix[0].size();
        vector<int> res(len * height);
        int half_height = height >> 1;
        int half_len = len >> 1;
        int k = 0;
        for (int i = 0; i < half_height && i < half_len; ++i) {
            int lower_bound = height - i - 1;
            int right_bound = len - i - 1;
            for (int j = i; j < right_bound; ++j) {
                res[k++] = matrix[i][j];
            }
            for (int j = i; j < lower_bound; ++j) {
                res[k++] = matrix[j][right_bound];
            }
            for (int j = i; j < right_bound; ++j) {
                res[k++] = matrix[lower_bound][right_bound + i - j];
            }
            for (int j = i; j < lower_bound; ++j) {
                res[k++] = matrix[lower_bound + i - j][i];
            }
        }
        if (height <= len && height & 1) {
            int right_bound = len - half_height;
            for (int j = half_height; j < right_bound; ++j) {
                res[k++] = matrix[half_height][j];
            }
        } else if (len & 1) {
            int lower_bound = height - half_len;
            for (int j = half_len; j < lower_bound; ++j) {
                res[k++] = matrix[j][half_len];
            }
        }
        return res;
    }
};
 */

/* class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        int height = matrix.size();
        int len = matrix[0].size();
        int left_bound = 0, right_bound = len - 1;
        int lower_bound = 0, upper_bound = height - 1;
        while (left_bound < right_bound && lower_bound < upper_bound) {
            for (int j = left_bound; j <= right_bound; ++j) {
                res.push_back(matrix[lower_bound][j]);
            }
            for (int i = lower_bound + 1; i <= upper_bound; ++i) {
                res.push_back(matrix[i][right_bound]);
            }
            for (int j = right_bound - 1; j > left_bound; --j) {
                res.push_back(matrix[upper_bound][j]);
            }
            for (int i = upper_bound; i > lower_bound; --i) {
                res.push_back(matrix[i][left_bound]);
            }
            ++left_bound;
            ++lower_bound;
            --right_bound;
            --upper_bound;
        }
        if (left_bound - 1 != right_bound && lower_bound - 1 != upper_bound) {
            for (int j = left_bound; j <= right_bound; ++j) {
                res.push_back(matrix[lower_bound][j]);
            }
            for (int i = lower_bound + 1; i <= upper_bound; ++i) {
                res.push_back(matrix[i][right_bound]);
            }
        }
        return res;
    }
}; */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        int height = matrix.size();
        int len = matrix[0].size();
        vector<int> x_mvoe = {1, 0, -1, 0};
        vector<int> y_move = {0, 1, 0, -1};
        vector<vector<int>> visit(height, vector<int>(len, 0));

        int di = 0;
        int x = 0, y = 0;
        int size = height * len;
        for (int i = 0; i < size; ++i) {
            res.push_back(matrix[y][x]);
            visit[y][x] = 1;
            int x_tmp = x + x_mvoe[di];
            int y_tmp = y + y_move[di];
            if (x_tmp >= 0 && x_tmp < len && y_tmp >= 0 && y_tmp < height && !visit[y_tmp][x_tmp]) {
                x = x_tmp;
                y = y_tmp;
            } else {
                di = (di + 1) % 4;
                x += x_mvoe[di];
                y += y_move[di];
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}};
    auto res = solution.spiralOrder(matrix);
    return 0;
}