// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         int size = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> res;
//         res.push_back(nums);

//         int m, k;
//         bool flag = true;
//         for(;;) {
//             flag = false;
//             for (m = size - 1; m > 0; --m) {
//                 if (nums[m] > nums[m - 1]) {
//                     flag = true;
//                     break;
//                 }
//             }
//             --m;
//             if (flag) {
//                 for (k = m + 1; (k < size - 1) && (nums[k + 1] > nums[m]); ++k);
//                 swap(nums[m], nums[k]);
//                 auto iter = nums.begin();
//                 iter += m + 1;
//                 reverse(iter, nums.end());
//                 vector<int> tmp;
//                 for (int i = 0; i < size; ++i) {
//                     tmp.push_back(nums[i]);
//                 }
//                 res.push_back(tmp);
//             } else {
//                 break;
//             }
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> res;
//         backtrack(nums, res, 0);
//         return res;
//     }

//     void backtrack(vector<int>& nums, vector<vector<int>>& res, int begin) {
//         if (begin == nums.size()) {
//             res.push_back(nums);
//             return;
//         }
//         unordered_set<int> set_;
//         for (int i = begin; i < nums.size(); ++i) {
//             if (set_.find(nums[i]) == set_.cend()) {
//                 set_.insert(nums[i]);
//                 swap(nums[i], nums[begin]);
//                 backtrack(nums, res, begin + 1);
//                 swap(nums[i], nums[begin]);
//             }
//         }
//     }
// };