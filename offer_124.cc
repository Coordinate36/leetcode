/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int ans = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        maxPathSum_(root);
        return ans;
    }

    int maxPathSum_(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxPathSum_(root->left);
        int right = maxPathSum_(root->right);
        int max_path = max(max(0, left), right) + root->val;
        ans = max(ans, max(0, left) + root->val + max(0, right));
        return max_path;
    }
};