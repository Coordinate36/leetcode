#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        if (m + n != s3.length()) {
            return false;
        }
        bool dp[m+1][n+1];
        dp[0][0] = true;
        for (int i = 0; i < m; ++i) {
            dp[i+1][0] = dp[i][0] && s1[i] == s3[i];
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j+1] = dp[0][j] && s2[j] == s3[j];
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i+1][j+1] = (dp[i][j+1] && s1[i] == s3[i+j+1]) || (dp[i+1][j] && s2[j] == s3[i+j+1]);
            }
        }
        return dp[m][n];
    }
};


int main() {
    auto solution = Solution();
    printf("%d\n", solution.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    return 0;
}
