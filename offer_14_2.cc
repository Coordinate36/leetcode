#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;


class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2 || n == 3) {
            return n - 1;
        }
        unsigned ans = 1;
        while (n > 4) {
            ans = (ans * 3) % 1000000007;
            n -= 3;
        }
        ans = (ans * n) % 1000000007;
        return ans;
    }
};


int main() {
    auto solution = Solution();
    cout << solution.cuttingRope(100) << endl;
    return 0;
}
