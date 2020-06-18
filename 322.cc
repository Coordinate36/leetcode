// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount + 1, INT_MAX - 1);
//         dp[0] = 0;
//         for (int i = 1; i <= amount; ++i) {
//             for (int j = 0; j < coins.size(); ++j) {
//                 if (i >= coins[j]) {
//                     dp[i] = min(dp[i], dp[i-coins[j]] + 1);
//                 }
//             }
//         }
//         return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
//     }
// };


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int res = INT_MAX;
        dfs(coins, amount, coins.size() - 1, 0, res);
        return res == INT_MAX ? -1 : res;
    }

    void dfs(vector<int>& coins, int target, int start, int cur, int &res) {
        if (start == -1) {
            return;
        }
        if (target % coins[start] == 0) {
            res = min(res, cur + target / coins[start]);
            return;
        }
        for (int i = target/coins[start]; i >= 0; --i) {
            if (cur + i >= res) {
                break;
            }
            dfs(coins, target - i * coins[start], start - 1, cur + i, res);
        }
    }
};