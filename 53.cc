#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < size; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}