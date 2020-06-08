class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int helper[31] = {0};
        for (auto num : nums) {
            int bit = 1;
            for (int i = 0; i < 31; ++i) {
                if (bit & num) {
                    helper[i]++;
                }
                bit <<= 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            if (helper[i] % 3) {
                ans += 1 << i;
            }
        }
        return ans;
    }
};