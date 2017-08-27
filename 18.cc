class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                int l = j + 1; 
                int r = nums.size() - 1;
                // cout << "i: " << i << ", j: " << j << ", l: " << l << ", r: " << r << endl;
                while (l < r) {
                    if (nums[i] + nums[j] + nums[l] + nums[r] == target) {
                        vector<int> ans = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(ans);
                        while (l < r && nums[l + 1] == nums[l]) {
                            ++l;
                        }
                        while (l < r && nums[r - 1] == nums[r]) {
                            --r;
                        }
                        ++l;
                        --r;
                    } else if (nums[i] + nums[j] + nums[l] + nums[r] < target) {
                        ++l;
                    } else {
                        --r;
                    }
                }
                while (nums[j + 1] == nums[j]) {
                    ++j;
                }
            }
            while (nums[i + 1] == nums[i]) {
                ++i;
            }
        }
        return res;
    }
};