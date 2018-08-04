struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return sum == root->val;
        }
        if (root->left && hasPathSum(root->left, sum - root->val)) {
            return true;
        }
        if (root->right && hasPathSum(root->right, sum - root->val)) {
            return true;
        }
        return false;
    }
};