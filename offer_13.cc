#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<int> bit_sum(max(n, m), -1);
        vector<pair<int, int>> move;
        move.push_back(make_pair(1, 0));
        move.push_back(make_pair(-1, 0));
        move.push_back(make_pair(0, 1));
        move.push_back(make_pair(0, -1));
        // visited[0][0] = 1;
        // return dfs(visited, bit_sum, move, m, n, 0, 0, k) + 1;
        return bfs(visited, bit_sum, move, m, n, k);
    }

    int dfs(vector<vector<int>>& visited, vector<int>& bit_sum, vector<pair<int, int>>& move, int m, int n, int row, int col, int k) {
        int ans = 0;
        for (auto &p : move) {
            int new_row = row + p.first;
            int new_col = col + p.second;
            if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && !visited[new_row][new_col]) {
                if (bit_sum[new_row] == -1) {
                    bit_sum[new_row] = _bit_sum(new_row);
                }
                if (bit_sum[new_col] == -1) {
                    bit_sum[new_col] = _bit_sum(new_col);
                }
                visited[new_row][new_col] = 1;
                if (bit_sum[new_row] + bit_sum[new_col] <= k) {
                    ans += dfs(visited, bit_sum, move, m, n, new_row, new_col, k) + 1;
                }
            }
        }
        return ans;
    }

    int bfs(vector<vector<int>>& visited, vector<int>& bit_sum, vector<pair<int, int>>& moves, int m, int n, int k) {
        int ans = 1;
        queue<pair<int, int>> q;
        visited[0][0] = 1;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            auto &point = q.front();
            q.pop();
            for (auto &move : moves) {
                int row = point.first + move.first;
                int col = point.second + move.second;
                if (row >= 0 && row < m && col >= 0 && col < n && !visited[row][col]) {
                    if (bit_sum[row] == -1) {
                        bit_sum[row] = _bit_sum(row);
                    }
                    if (bit_sum[col] == -1) {
                        bit_sum[col] = _bit_sum(col);
                    }
                    visited[row][col] = 1;
                    if (bit_sum[row] + bit_sum[col] <= k) {
                        ans++;
                        q.push(make_pair(row, col));
                    }
                }
            }
        }
        return ans;
    }

    int _bit_sum(int n) {
        int rst = 0;
        while (n) {
            rst += n % 10;
            n /= 10;
        }
        return rst;
    }
};


int main() {
    auto solution = Solution();
    cout << solution.movingCount(11, 8, 6) << endl;
    // cout << solution.movingCount(2, 3, 1) << endl;
    return 0;
}
