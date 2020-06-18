class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        vector<int> path;
        _pathSum(root, sum, ans, path);
        return ans;
    }

    void _pathSum(TreeNode* root, int sum, vector<vector<int>>& ans, vector<int>& path) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        int target = sum - root->val;
        if (root->left == nullptr && root->right == nullptr && root->val == sum) {
            ans.push_back(path);
        }
        _pathSum(root->left, target, ans, path);
        _pathSum(root->right, target, ans, path);
        path.pop_back();
    }
};