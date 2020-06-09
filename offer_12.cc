// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         if (board.empty() || word.empty()) {
//             return word.empty();
//         }
//         vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
//         for (int i = 0; i < board.size(); ++i) {
//             for (int j = 0; j < board[0].size(); ++j) {
//                 visited[i][j] = 1;
//                 if (board[i][j] == word[0] && _exist(board, i, j, visited, word, 1)) {
//                     return true;
//                 }
//                 visited[i][j] = 0;
//             }
//         }
//         return false;
//     }

//     bool _exist(vector<vector<char>>& board, int row, int col, vector<vector<int>>& visited, string& word, int next) {
//         if (next == word.length()) {
//             return true;
//         }
//         if (row > 0 && !visited[row-1][col] && board[row-1][col] == word[next]) {
//             visited[row-1][col] = 1;
//             if (_exist(board, row - 1, col, visited, word, next + 1)) {
//                 return true;
//             }
//             visited[row-1][col] = 0;
//         }
//         if (row < board.size() - 1 && !visited[row+1][col] && board[row+1][col] == word[next]) {
//             visited[row+1][col] = 1;
//             if (_exist(board, row + 1, col, visited, word, next + 1)) {
//                 return true;
//             }
//             visited[row+1][col] = 0;
//         }
//         if (col > 0 && !visited[row][col-1] && board[row][col-1] == word[next]) {
//             visited[row][col-1] = 1;
//             if (_exist(board, row, col - 1, visited, word, next + 1)) {
//                 return true;
//             }
//             visited[row][col-1] = 0;
//         }
//         if (col < board[0].size() -1 && !visited[row][col+1] && board[row][col+1] == word[next]) {
//             visited[row][col+1] = 1;
//             if (_exist(board, row, col + 1, visited, word, next + 1)) {
//                 return true;
//             }
//             visited[row][col+1] = 0;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) {
            return word.empty();
        }
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                visited[i][j] = 1;
                if (board[i][j] == word[0] && _exist(board, i, j, visited, word, 1)) {
                    return true;
                }
                visited[i][j] = 0;
            }
        }
        return false;
    }

    bool _exist(vector<vector<char>>& board, int row, int col, vector<vector<int>>& visited, string& word, int next) {
        if (next == word.length()) {
            return true;
        }
        if (row > 0 && !visited[row-1][col] && board[row-1][col] == word[next]) {
            visited[row-1][col] = 1;
            if (_exist(board, row - 1, col, visited, word, next + 1)) {
                return true;
            }
            visited[row-1][col] = 0;
        }
        if (row < board.size() - 1 && !visited[row+1][col] && board[row+1][col] == word[next]) {
            visited[row+1][col] = 1;
            if (_exist(board, row + 1, col, visited, word, next + 1)) {
                return true;
            }
            visited[row+1][col] = 0;
        }
        if (col > 0 && !visited[row][col-1] && board[row][col-1] == word[next]) {
            visited[row][col-1] = 1;
            if (_exist(board, row, col - 1, visited, word, next + 1)) {
                return true;
            }
            visited[row][col-1] = 0;
        }
        if (col < board[0].size() -1 && !visited[row][col+1] && board[row][col+1] == word[next]) {
            visited[row][col+1] = 1;
            if (_exist(board, row, col + 1, visited, word, next + 1)) {
                return true;
            }
            visited[row][col+1] = 0;
        }
        return false;
    }
};