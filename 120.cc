class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) {
            return 0;
        }
        int size = triangle.size();
        int dp[size];
        dp[0] = triangle[0][0];
        for (int i = 1; i < size; ++i) {
            dp[i] = dp[i-1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j) {
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        int ans = dp[0];
        for (int j = 1; j < size; ++j) {
            ans = min(ans, dp[j]);
        }
        return ans;
    }
};