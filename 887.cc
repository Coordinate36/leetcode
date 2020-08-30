#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, INT_MAX));
        return dfs(K, N, dp);
    }

    int dfs(int K, int N, vector<vector<int>>& dp) {
        if (K == 1 || N == 0) {
            dp[K][N] = N;
            return N;
        }
        if (dp[K][N] != INT_MAX) {
            return dp[K][N];
        }
        int left = 1, right = N;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (dfs(K - 1, mid - 1, dp) <= dfs(K, N - mid, dp)) {
                dp[K][N] = min(dp[K][N], dfs(K, N - mid, dp) + 1);
                left = mid + 1;
            } else {
                dp[K][N] = min(dp[K][N], dfs(K - 1, mid - 1, dp) + 1);
                right = mid - 1;
            }
        }
        return dp[K][N];
    }
};


int main() {
    Solution solution;
    cout << solution.superEggDrop(8, 5000) << endl;
    return 0;
}