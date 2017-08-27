// class Solution {
// public:
//     int reverse(int x) {
//         if (x == -2147483648) {
//             return 0;
//         }
//         int m, n;
//         long long ans = 0;
//         int isPositive = x >= 0;
//         int tmp = isPositive ? x: -x;
//         while (tmp != 0) {
//             m = tmp / 10;
//             n = tmp - m * 10;
//             ans = ans * 10 + n;
//             tmp = m;
//         }
//         long long size = 1 << 30;
//         size = size * 2;
//         // cout << "x: " << x << ", ans: " << ans << ", size: " << size << endl;
//         if ((isPositive && ans >= size) || (!isPositive && ans > size)) {
//             return 0;
//         }
//         return isPositive ? ans: -ans;
//     }
// };

class Solution {
public:
    int reverse(int x) {
        int tmp = x;
        int res = 0;
        int upperBound = INT_MAX / 10;
        int downBound = INT_MIN / 10;
        while(tmp != 0){
            if(res > upperBound || res < downBound){
                return 0;
            }
            res = res * 10 + tmp % 10;
            tmp = tmp / 10;
        }
        return res;
    }
};