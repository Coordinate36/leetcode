#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* class Solution {
public:
    int uniquePaths(int m, int n) {
        int step_num = m + n - 2;
        long long ans = 1;
        m = min(m, n);
        for (int i = 0; i < m - 1; ++i) {
            ans *= step_num - i;
        }
        for (int i = 2; i < m; ++i) {
            ans /= i;
        }
        return ans;
    }
}; */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution solution;
    auto ans = solution.uniquePaths(10, 10);
    cout << ans;
    return 0;
}