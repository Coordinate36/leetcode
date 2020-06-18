class Solution {
public:
    int sumNums(int n) {
        int A = n, B = n + 1, ans = 0;
        while (A) {
            (A & 1) && (ans += B);
            A >>= 1;
            B <<= 1;
        }
        return ans >> 1;
    }
};