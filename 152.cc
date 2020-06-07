class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int cur_max = nums[0];
        int cur_min = nums[0];
        int v1, v2;
        for (auto i = 1; i < nums.size(); ++i) {
            v1 = cur_max * nums[i];
            v2 = cur_min * nums[i];
            cur_max = v1 > v2 ? max(v1, nums[i]) : max(v2, nums[i]);
            cur_min = v1 < v2 ? min(v1, nums[i]) : min(v2, nums[i]);
            ans = max(ans, cur_max);
        }
        return ans;
    }
};