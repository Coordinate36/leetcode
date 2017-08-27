/*class Solution {
public:
    bool isMatch(string s, string p) {
        int sSize = s.size();
        int pSize = p.size();
        if (pSize == 0) {
            return sSize == 0;
        }
        if (pSize == 1 || p[1] != '*') {
            if (sSize == 0 || (s[0] != p[0] && p[0] != '.')) {
                return false;
            } else {
                return isMatch(s.substr(1), p.substr(1));
            }
        }
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2))) {
                return true;
            }
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int sSize = s.size();
        int pSize = p.size();
        int dp[sSize + 1][pSize + 1]; // dp[i][j]: s[0...i-1] matches p[0...j-1]
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int j = 1; j <= pSize; ++j) {
            dp[0][j] = j > 1 && p[j - 1] == '*' && dp[0][j - 2];
        }
        for (int i = 1; i <= sSize; ++i) {
            for (int j = 1; j <= pSize; ++j) {
                if (p[j - 1] != '*') {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                } else {
                    dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && dp[i - 1][j];
                }
            }
        }
        return dp[sSize][pSize];
    }
};
