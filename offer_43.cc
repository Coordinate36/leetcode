// class Solution {
// public:
//     int countDigitOne(int n) {
//         int log = -1;
//         for (long long m = 1; m <= n; m *= 10) {
//             ++log;
//         }
//         if (log <= 0) {
//             return n >= 1;
//         }
//         int map_[log];
//         map_[0] = 1;
//         int m = 10;
//         for (int i = 1; i < log; ++i) {
//             map_[i] = map_[i-1] * 10 + m;
//             m *= 10;
//         }
//         int ans = 0;
//         for (int i = log - 1; i >= 0; --i) {
//             if (n >= m) {
//                 int div = n / m;
//                 ans += map_[i] * div + min(m, n - m + 1);
//                 n -= div * m;
//             }
//             m /= 10;
//         }
//         if (n) {
//             ++ans;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        long long digit = 1;
        int high = n / 10;
        int cur = n - high * 10;
        int low = 0;
        while (high || cur) {
            if (cur == 0) {
                ans += high * digit;
            } else if (cur == 1) {
                ans += high * digit + low + 1;
            } else {
                ans += (high + 1) * digit;
            }
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return ans;
    }
};