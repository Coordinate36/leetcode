class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        for (int i = 0; i <= nums.size(); ++i) {
            backtrack(nums, res, cur, 0, i);
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
        }
    }
};