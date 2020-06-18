class Solution {
public:
    int add(int a, int b) {
        while(b != 0) {
            int c = (unsigned)(a & b) << 1;
            a ^= b; // a = 非进位和
            b = c;  // b = 进位和
        }
        return a;
    }
};