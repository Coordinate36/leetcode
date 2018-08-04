#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        int row_border = board.size() - 1;
        int col_border = board[0].size() - 1;
        for (int i = 0; i <= row_border; i++) {
            if (board[i][0] == 'O') {
                dfs(board, make_pair(i, 0), row_border, col_border);
            }
            if (board[i][col_border] == 'O') {
                dfs(board, make_pair(i, col_border), row_border, col_border);
            }
        }

        for (int i = 0; i <= col_border; i++) {
            if (board[0][i] == 'O') {
                dfs(board, make_pair(0, i), row_border, col_border);
            }
            if (board[row_border][i] == 'O') {
                dfs(board, make_pair(row_border, i), row_border, col_border);
            }
        }

        for (int i = 0; i <= row_border; i++) {
            for (int j = 0; j <= col_border; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 0) {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, pair<int, int> coordinate, int row_border, int col_border) {
        stack<pair<int, int>> Stack;
        pair<int, int> cur;
        Stack.push(coordinate);
        while (!Stack.empty()) {
            cur = Stack.top();
            Stack.pop();
            board[cur.first][cur.second] = 0;
            if (cur.first > 0 && board[cur.first - 1][cur.second] == 'O') {
                Stack.push(make_pair(cur.first - 1, cur.second));
            }
            if (cur.first < row_border && board[cur.first + 1][cur.second] == 'O') {
                Stack.push(make_pair(cur.first + 1, cur.second));
            }
            if (cur.second > 0 && board[cur.first][cur.second - 1] == 'O') {
                Stack.push(make_pair(cur.first, cur.second - 1));
            }
            if (cur.second < col_border && board[cur.first][cur.second + 1] == 'O') {
                Stack.push(make_pair(cur.first, cur.second + 1));
            }
        }
    }
};