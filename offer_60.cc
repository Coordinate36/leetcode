// class Solution {
// public:
//     vector<double> twoSum(int n) {
//         vector<double> ans;
//         int dp[n+1][6*n+1];
//         memset(dp, 0, sizeof(dp));
//         for (int j = 1; j <= 6; ++j) {
//             dp[1][j] = 1;
//         }
//         for (int i = 2; i <= n; ++i) {
//             for (int j = i; j <= 6 * i; ++j) {
//                 for (int k = max(i - 1, j - 6); k < j; ++k) {
//                     dp[i][j] += dp[i-1][k];
//                 }
//             }
//         }
//         int sum = 0;
//         for (int j = n; j <= 6 * n; ++j) {
//             sum += dp[n][j];
//         }
//         for (int j = n; j <= 6 * n; ++j) {
//             ans.emplace_back(double(dp[n][j]) / double(sum));
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> ans;
        int dp[6*n+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 6; ++i) {
            dp[i] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 6 * i; j >= i; --j) {
                dp[j] = 0;
                for (int k = max(i - 1, j - 6); k < j; ++k) {
                    dp[j] += dp[k];
                }
            }
        }
        int sum = 0;
        for (int i = 6 * n; i >= n; --i) {
            sum += dp[i];
        }
        for (int i = n; i <= 6 * n; ++i) {
            ans.emplace_back(double(dp[i]) / double(sum));
        }
        return ans;
    }
};