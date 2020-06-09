class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        double cur = x;
        bool positive = (n >= 0);
        if (!positive) {
            n = -(n + 1);
            ans = x;
        }
        while (n) {
            if (n & 1) {
                ans *= cur;
            }
            cur *= cur;
            n >>= 1;
        }
        return positive ? ans : 1/ans;
    }
};