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
public:
    TreeNode* lca;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return lca;
    }

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }
        bool ans = (root == p || root == q);
        bool left = dfs(root->left, p, q);
        if (ans && left) {
            lca = root;
        }
        if (lca) {
            return root;
        }
        ans |= left;
        bool right = dfs(root->right, p, q);
        if (ans && right) {
            lca = root;
        }
        ans |= right;
        return ans;
    }
};