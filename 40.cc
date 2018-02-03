class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        findSum(candidates, 0, target, ans);
        return res;
    }

    void findSum(vector<int> &candidates, int begin, int target, vector<int> ans) {
        if (target == 0) {
            res.push_back(ans);
            return;
        }

        for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i) {
            if (i > begin && candidates[i] == candidates[i - 1]) {
                continue;
            }
            ans.push_back(candidates[i]);
            findSum(candidates, i + 1, target - candidates[i], ans);
            ans.pop_back();
        }
    }
};