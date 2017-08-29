class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        if (divisor + 1 == -INT_MAX) {
            return dividend == -INT_MAX - 1;
        }
        int flag = 0;
        int is_positive = (divisor > 0 && dividend > 0) || (divisor < 0 && dividend < 0); 
        divisor = abs(divisor);
        if (dividend + 1 == -INT_MAX) {
            dividend += divisor;
            flag = 1;
        }
        dividend = abs(dividend);
        int high = 0;
        int ans = 0;
        for (high = 0; (dividend - (divisor << high) >= 0) && (dividend - (divisor << high) - (divisor << high) >= 0); ++high);
        for (int i = high; i >= 0; --i) {
            if (dividend >= (divisor << i)) {
                dividend -= divisor << i;
                ans += 1 << i;
            }
        }
        if (ans == INT_MAX && is_positive == 1) {
            return INT_MAX;
        }
        return is_positive ? ans + flag: -(ans + flag);
    }
};