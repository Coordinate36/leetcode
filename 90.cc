class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        for (int len = 0; len <= nums.size(); ++len) {
            backtrack(nums, res, cur, 0, len);
        }
        return res;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int begin, int len) {
        if (cur.size() == len) {
            res.push_back(cur);
            return;
        }
        for (int i = begin; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            backtrack(nums, res, cur, i + 1, len);
            cur.pop_back();
            while (i + 1 < nums.size() && nums[i+1] == nums[i]) {
                ++i;
            }
        }
    }
};