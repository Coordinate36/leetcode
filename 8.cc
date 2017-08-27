class Solution {
public:
    int myAtoi(string str) {
        int i;
        int size = str.size();
        int isPositive = 1;
        long long ans = 0;
        for (i = 0; str[i] == ' ' && i < size; ++i);
        if (i == size) {
            return 0;
        }
        if (str[i] == '+') {
            ++i;
        } else if (str[i] == '-') {
            isPositive = -1;
            ++i;
        }
        
        while (i < size && '0' <= str[i] && str[i] <= '9') {
            ans = ans * 10 + str[i++] - '0';
            if (isPositive == 1 && ans > 2147483647) {
                return 2147483647;
            }
            if (isPositive == -1 && ans > 2147483648) {
                return -2147483648;
            }
        }

        return isPositive == 1 ? ans: -ans;
    }
};