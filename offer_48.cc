class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int dp = 1;
        int ans = 1;
        for (int i = 1; i < s.length(); ++i) {
            int j = 1;
            for (; j <= dp; ++j) {
                if (s[i-j] == s[i]) {
                    break;
                }
            }
            dp = j;
            ans = max(dp, ans);
        }
        return ans;
    }
};