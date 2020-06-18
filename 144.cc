/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        auto p = root;
        while (!st.empty() || p) {
            if (p) {
                ans.push_back(p->val);
                st.push(p);
                p = p->left;
            } else {
                auto pre = st.top();
                st.pop();
                p = pre->right;
            }
        }
        return ans;
    }
};