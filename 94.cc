#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        stack<TreeNode*> st;
        auto p = root;
        while (!st.empty() || p) {
            if (p == nullptr) {
                auto pre = st.top();
                st.pop();
                ans.push_back(pre->val);
                p = pre->right;
            } else {
                st.push(p);
                p = p->left;
            }
        }
        return ans;
    }
};