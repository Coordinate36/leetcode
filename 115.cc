#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.length() == 0 || t.length() == 0 || s.length() < t.length()) {
            return 0;
        }
        int dp[t.length()][s.length()];
        memset(dp, 0, sizeof(dp));
        int n = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == t[0]) {
                dp[0][i] = ++n;
            } else {
                dp[0][i] = n;
            }
        }
        for (int i = 1; i < t.length(); i++) {
            dp[i][i - 1] = 0;
            for (int j = i; j < s.length(); j++) {
                if (s[j] == t[i]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[t.length() - 1][s.length() - 1];
    }
};