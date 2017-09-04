class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i;
        for (i = size - 1; i > 0 && nums[i - 1] >= nums[i]; --i);
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        --i;
        for (int j = size - 1; j >= 0; --j) {
            // cout << i << " " << j << endl;
            if (nums[j] > nums[i]) {
                // cout << i << " " << j << endl;
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
    }
};