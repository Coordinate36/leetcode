class Solution {
public:
    int findNthDigit(int n) {
        int ans = 0;
        int mul = 1;
        for (int i = 1;; ++i) {
            int tmp = mul * 9 * i;
            if (n >= tmp) {
                ans += mul * 9;
                n -= tmp;
            } else {
                ans += n / i;
                break;
            }
        }
        return ans;
    }
};