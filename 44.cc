#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();
        vector<vector<int>> dp(p_len + 1, vector<int>(s_len + 1));
        dp[0][0] = 1;
        int start = 0;
        for (int i = 1; i <= p_len; ++i) {
            if (p[i - 1] == '*') {
                dp[i][0] = dp[i - 1][0];
                for (int j = 1; j <= s_len; ++j) {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j];
                }
            } else {
                ++start;
                for (int j = start; j <= s_len; ++j) {
                    if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[p_len][s_len];
    }
};

int main() {
    vector<string> strs = {
        "aa",
        "aa",
        "aaa",
        "aa",
        "aa",
        "ab",
        "aab",
        "",
        "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba"
    };
    vector<string> pats = {
        "a",
        "aa",
        "aa",
        "*",
        "a*",
        "?*",
        "c*a*b",
        "?",
        "a*******b"
    };
    Solution solution;
    for (int i = 0; i < strs.size(); ++i) {
        cout << solution.isMatch(strs[i], pats[i]) << endl;
    }
    return 0;
}