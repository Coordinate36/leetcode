class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> ans(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        for (auto num : nums) {
            if (num & 1) {
                ans[left++] = num;
            } else {
                ans[right--] = num;
            }
        }
        return ans;
    }
};