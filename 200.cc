// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty()) {
//             return 0;
//         }
//         vector<vector<char>> cloned(grid.cbegin(), grid.cend());
//         int ans = 0;
//         for (int row = 0; row < grid.size(); ++row) {
//             for (int col = 0; col < grid[0].size(); ++col) {
//                 if (cloned[row][col] == '1') {
//                     ++ans;
//                     bfs(cloned, row, col);
//                 }
//             }
//         }
//         return ans;
//     }

//     void bfs(vector<vector<char>>& grid, int row, int col) {
//         vector<pair<int, int>> st;
//         st.push_back({row, col});
//         while (st.size()) {
//             auto p = st.back();
//             grid[p.first][p.second] = 0;
//             st.pop_back();
//             if (p.first && grid[p.first-1][p.second] == '1') {
//                 st.push_back({p.first - 1, p.second});
//             }
//             if (p.first + 1 < grid.size() && grid[p.first+1][p.second] == '1') {
//                 st.push_back({p.first + 1, p.second});
//             }
//             if (p.second && grid[p.first][p.second-1] == '1') {
//                 st.push_back({p.first, p.second - 1});
//             }
//             if (p.second + 1 < grid[0].size() && grid[p.first][p.second+1] == '1') {
//                 st.push_back({p.first, p.second + 1});
//             }
//         }
//     }
// };


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        vector<vector<char>> cloned(grid.cbegin(), grid.cend());
        int ans = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (cloned[row][col] == '1') {
                    ++ans;
                    dfs(cloned, row, col);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = 0;
        if (row > 0 && grid[row-1][col] == '1') {
            dfs(grid, row - 1, col);
        }
        if (row + 1 < grid.size() && grid[row+1][col] == '1') {
            dfs(grid, row + 1, col);
        }
        if (col > 0 && grid[row][col-1] == '1') {
            dfs(grid, row, col - 1);
        }
        if (col + 1 < grid[0].size() && grid[row][col+1] == '1') {
            dfs(grid, row, col + 1);
        }
    }
};