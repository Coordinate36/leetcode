class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            twoSum(nums, i + 1, nums.size() - 1, nums[i]);
            while (nums[i + 1] == nums[i]) {
                ++i;
            }
        }
        return res;
    }
    
    void twoSum(vector<int> nums, int begin, int end, int first) {
        int left = begin;
        int right = end;
        while (left < right) {
            int sum = first + nums[left] + nums[right];
            if (sum < 0) {
                ++left;
            } else if (sum > 0) {
                --right;
            } else {
                vector<int> ans;
                ans.push_back(first);
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);
                res.push_back(ans);
                while (left < right && nums[left + 1] == nums[left]) {
                    ++left;
                }
                while (left < right && nums[right - 1] == nums[right]) {
                    --right;
                }
                ++left;
                --right;
            }
        }
    }
};