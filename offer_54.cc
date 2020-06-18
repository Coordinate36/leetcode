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
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* p = root;
        int ans = 0;
        while (k && (!st.empty() || p)) {
            if (p != nullptr) {
                st.push(p);
                p = p->right;
            } else {
                p = st.top();
                st.pop();
                --k;
                ans = p->val;
                p = p->left;
            }
        }
        return ans;
    }
};