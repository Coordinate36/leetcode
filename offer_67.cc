// class Solution {
// public:
//     int strToInt(string str) {
//         int beg = 0;
//         for (; beg < str.length() && str[beg] == ' '; ++beg);
//         if (beg == str.length()) {
//             return 0;
//         }
//         bool positive = true;
//         if (str[beg] == '+' || str[beg] == '-') {
//             positive = str[beg++] == '+';
//         } else if (str[beg] > '9' || str[beg] < '0') {
//             return 0;
//         }
//         long long ans = 0;
//         for (int i = beg; i < str.length() && str[i] >= '0' && str[i] <= '9'; ++i) {
//             ans = ans * 10 + str[i] - '0';
//             if (positive && ans > INT_MAX) {
//                 return INT_MAX;
//             }
//             if (!positive && -ans < INT_MIN) {
//                 return INT_MIN;
//             }
//         }
//         return positive ? ans : -ans;
//     }
// };

class Solution {
public:
    int strToInt(string str) {
        int beg = 0;
        for (; beg < str.length() && str[beg] == ' '; ++beg);
        if (beg == str.length()) {
            return 0;
        }
        bool positive = true;
        if (str[beg] == '+' || str[beg] == '-') {
            positive = str[beg++] == '+';
        } else if (str[beg] > '9' || str[beg] < '0') {
            return 0;
        }
        unsigned ans = 0;
        int limit = INT_MAX / 10;
        int rest_limit = INT_MAX % 10;
        for (int i = beg; i < str.length() && str[i] >= '0' && str[i] <= '9'; ++i) {
            int rest = str[i] - '0';
            if (ans > limit) {
                return positive ? INT_MAX : INT_MIN;
            }
            if (ans == limit && rest > rest_limit) {
                if (positive) {
                    return INT_MAX;
                }
                if (rest > rest_limit + 1) {
                    return INT_MIN;
                }
            }
            ans = ans * 10 + rest;
        }
        return positive ? ans : -ans;
    }
};