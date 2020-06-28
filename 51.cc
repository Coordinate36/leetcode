// #include <iostream>
// #include <algorithm>
// #include <map>
// #include <string>
// #include <vector>
// #include <cmath>

// using namespace std;

// class Solution {
// public:
//     vector<vector<string>> res;
//     vector<vector<string>> solveNQueens(int n) {
//         vector<string> ans = vector<string>(n, string(n, '.'));
//         vector<vector<int>> board = vector<vector<int>>(n, vector<int>(n, 0));
//         dfs(board, ans, 0, n);
//         return res;
//     }

//     void dfs(vector<vector<int>> &board, vector<string> &ans, int i, int n) {
//         if (i == n) {
//             res.push_back(ans);
//             return;
//         }
//         int j;
//         for (j = 0; j < n; ++j) {
//             if (board[i][j] == 0) {
//                 ans[i][j] = 'Q';
//                 for (int k = 0; k < n; ++k) {
//                     board[i][k] += 1;
//                     board[k][j] += 1;
//                     int y1 = j - i + k;
//                     int y2 = j + i - k;
//                     if (y1 >= 0 && y1 < n) board[k][y1] += 1;
//                     if (y2 >= 0 && y2 < n) board[k][y2] += 1;
//                 }
//                 dfs(board, ans, i + 1, n);
//                 ans[i][j] = '.';
//                 for (int k = 0; k < n; ++k) {
//                     board[i][k] -= 1;
//                     board[k][j] -= 1;
//                     int y1 = j - i + k;
//                     int y2 = j + i - k;
//                     if (y1 >= 0 && y1 < n) board[k][y1] -= 1;
//                     if (y2 >= 0 && y2 < n) board[k][y2] -= 1;
//                 }
//             }
//         }
//     }
// };

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> res;
        backtrack(board, 0, res);
        return res;
    }

    void backtrack(vector<vector<int>>& board, int row, vector<vector<string>>& res) {
        int n = board.size();
        if (row == n) {
            vector<string> grid(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j]) {
                        grid[i][j] = 'Q';
                    }
                }
            }
            res.emplace_back(grid);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (isValidPos(board, row, i)) {
                board[row][i] = 1;
                backtrack(board, row + 1, res);
                board[row][i] = 0;
            }
        }
    }

    bool isValidPos(vector<vector<int>>& board, int row, int col) {
        int n = board.size();
        for (int i = 0; i < n; ++i) {
            if (board[i][col] || board[row][i]) {
                return false;
            }
        }
        for (int r = row + 1, c = col + 1; r < n && c < n; ++r, ++c) {
            if (board[r][c]) {
                return false;
            }
        }
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; --r, --c) {
            if (board[r][c]) {
                return false;
            }
        }
        for (int r = row + 1, c = col - 1; r < n && c >= 0; ++r, --c) {
            if (board[r][c]) {
                return false;
            }
        }
        for (int r = row - 1, c = col + 1; r >= 0 && c < n; --r, ++c) {
            if (board[r][c]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    auto res = solution.solveNQueens(8);
    return 0;
}