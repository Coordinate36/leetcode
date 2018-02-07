#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        if (n == 0) {
            return res;
        }
        vector<int> x_move = {1, 0, -1, 0};
        vector<int> y_move = {0, 1, 0, -1};
        int di = 0;
        int k = 1;
        int x = 0, y = 0;
        vector<vector<int>> visit(n, vector<int>(n, 0));
        for (int i = 0; i < n * n; ++i) {
            res[y][x] = k++;
            visit[y][x] = 1;
            int x_tmp = x + x_move[di];
            int y_tmp = y + y_move[di];
            if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < n && !visit[y_tmp][x_tmp]) {
                x = x_tmp;
                y = y_tmp;
            } else {
                di = (di + 1) % 4;
                x += x_move[di];
                y += y_move[di];
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    auto res = solution.generateMatrix(3);
    return 0;
}