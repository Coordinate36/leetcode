// class Solution {
// public:
//     int findPos(char c, string str) {
//         for (int i = str.size() - 1; i != -1; --i) {
//             if (str[i] == c) {
//                 return i;
//             }
//         }
//         return -1;
//     }
//     int lengthOfLongestSubstring(string s) {
//         int size = s.size();
//         if (size == 0) {
//             return 0;
//         }
//         int dp[size];
//         dp[0] = 1;
//         for (int i = 1; i != size; ++i) {
//             int pos = findPos(s[i], s.substr(i - dp[i - 1], dp[i - 1]));
//             dp[i] = dp[i - 1] - pos;
//         }
//         int result = dp[0];
//         for (int i = 1; i != size; ++i) {
//             cout << i << ": " << dp[i] << endl;
//             result = max(result, dp[i]);
//         }
//         return result;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int ans = 0; // ans是s.substr(0, j)的最长子串长度
        map<char, int> hashmap; // 字符对应index + 1
        // 当最长子串包含s[j]时，s.substr(0, i)被舍去
        for (int i = 0, j = 0; j != size; ++j) {
            if (hashmap[s[j]]) {
                i = max(hashmap[s[j]], i);
            }
            ans = max(ans, j - i + 1);
            hashmap[s[j]] = j + 1;
        }
        return ans;
    }
};