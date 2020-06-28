// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> res;
//         backtrack(nums, res, 0);
//         return res;
//     }

//     void backtrack(vector<int>& nums, vector<vector<int>>& res, int begin) {
//         if (begin == nums.size()) {
//             res.push_back(nums);
//             return;
//         }
//         for (int i = begin; i < nums.size(); ++i) {
//             swap(nums[begin], nums[i]);
//             backtrack(nums, res, begin + 1);
//             swap(nums[begin], nums[i]);
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        result.push_back(nums);
        while(nextPermutation(nums)) {
            result.push_back(nums);
        }
        return result;
    }

    bool nextPermutation(vector<int>& nums) {
        int l = nums.size() - 2;
        for (; l >= 0 && nums[l] >= nums[l+1]; l--);
        if (l < 0) {
            return false;
        }
        int r = l + 1;
        for (; r < nums.size() && nums[r] > nums[l]; r++);
        swap(nums[l], nums[r-1]);
        reverse(nums.begin() + l + 1, nums.end());
        return true;
    }
};
