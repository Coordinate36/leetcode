#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;


class Solution {
public:
    int cuttingRope(int n) {
        int ans = 1;
        int res = n % 3;
        if (n == 2 || n == 3) {
            return n - 1;
        }
        if (res == 1) {
            ans = pow(3, n / 3 - 1) * (res + 3);
        } else if (res == 0) {
            ans = pow(3, n / 3);
        } else {
            ans = pow(3, n / 3) * 2;
        }
        return ans;
    }
};


int main() {
    auto solution = Solution();
    cout << solution.cuttingRope(5) << endl;
    return 0;
}

