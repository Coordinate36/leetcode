class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size();
        int dp[len];
        for (int i = 0; i < len; ++i) {
            dp[i] = 1;
        }

        for (int i = 1; i < len; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int res = dp[0];
        for (int i = 1; i < len; ++i) {
            res = max(res, dp[i]);
        }

        return res;
    }
};