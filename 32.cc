/*class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len));
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                dp[i][i] = 1;
            } else {
                dp[i][i] = -1;
            }
        } 

        for (int i = 1; i < len; ++i) {
            // dp[j][j + i] starts with j, lenth is i + 1
            for (int j = 0; j + i < len; ++j) {
                if (dp[j][j + i - 1] >= 0) {
                    dp[j][j + i] = dp[j][j + i - 1] + dp[j + i][j + i];
                } else {
                    dp[j][j + i] = -len;
                }
            }
        }

        for (int i = len - 1; i >= 0; --i) {
            for (int j = 0; j + i < len; ++j) {
                if (dp[j][j + i] == 0) {
                    return (i + 1);
                }
            }
        }

        return 0;
    }
};*/

/*class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len == 0) {
            return 0;
        }
        int res = 0;
        vector<int> dp(len);
        for (int i = 1; i < len; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i > 2 ? dp[i - 2]: 0) + 2;
                } else if ((i - dp[i - 1] > 0) && (s[i - 1 - dp[i - 1]] == '(')) {
                    dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] > 1 ? dp[i - dp[i - 1] - 2]: 0);
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};
*/

/*class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> brackets; // 最近已匹配部分的起始位置的前一个位置
        brackets.push(-1);
        int len = s.size();
        int res = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                brackets.push(i);
            } else {
                brackets.pop();
                if (brackets.size()) {
                    res = max(res, i - brackets.top());
                } else {
                    brackets.push(i);
                }
            }
        }
        return res;
    }
};*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int left = 0, right = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
            if (left == right) {
                res = max(res, left * 2);
            } else if (left < right) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = len - 1; i >= 0; --i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
            if (left == right) {
                res = max(res, left * 2);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return res;
    }
};