class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int tmp = x;
        int m, n;
        int reversedNum = 0;
        while (tmp) {
            m = tmp / 10;
            n = tmp - m * 10;
            reversedNum = reversedNum * 10 + n;
            tmp = m;
        }
        return reversedNum == x;
    }
};