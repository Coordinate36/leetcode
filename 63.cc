#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> obstacleGrid = {{0,0,0}, {0,1,0}, {0,0,0}};
    auto ans = solution.uniquePathsWithObstacles(obstacleGrid);
    cout << ans;
    return 0;
}