class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> ans(2);
        int ret = 0;
        for (auto n : nums) {
            ret ^= n;
        }
        int bit = 1;
        for (int i = 0; i < 14; ++i) {
            if (bit & ret) {
                break;
            }
            bit <<= 1;
        }
        for (auto n: nums) {
            if (n & bit) {
                ans[0] ^= n;
            } else {
                ans[1] ^= n;
            }
        }
        return ans;
    }
};