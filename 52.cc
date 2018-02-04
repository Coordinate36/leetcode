#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int res;
    int totalNQueens(int n) {
        vector<string> ans = vector<string>(n, string(n, '.'));
        vector<vector<int>> board = vector<vector<int>>(n, vector<int>(n, 0));
        dfs(board, ans, 0, n);
        return res;
    }

    void dfs(vector<vector<int>> &board, vector<string> &ans, int i, int n) {
        if (i == n) {
            ++res;
            return;
        }
        int j;
        for (j = 0; j < n; ++j) {
            if (board[i][j] == 0) {
                ans[i][j] = 'Q';
                for (int k = 0; k < n; ++k) {
                    board[i][k] += 1;
                    board[k][j] += 1;
                    int y1 = j - i + k;
                    int y2 = j + i - k;
                    if (y1 >= 0 && y1 < n) board[k][y1] += 1;
                    if (y2 >= 0 && y2 < n) board[k][y2] += 1;
                }
                dfs(board, ans, i + 1, n);
                ans[i][j] = '.';
                for (int k = 0; k < n; ++k) {
                    board[i][k] -= 1;
                    board[k][j] -= 1;
                    int y1 = j - i + k;
                    int y2 = j + i - k;
                    if (y1 >= 0 && y1 < n) board[k][y1] -= 1;
                    if (y2 >= 0 && y2 < n) board[k][y2] -= 1;
                }
            }
        }
    }
};

int main() {
    Solution solution;
    auto res = solution.totalNQueens(8);
    cout << res << endl;
    return 0;
}