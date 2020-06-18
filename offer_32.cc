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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        bool flag = true;
        deque<TreeNode*> deq;
        deq.push_back(root);
        while (!deq.empty()) {
            int level_num = deq.size();
            vector<int> level(level_num);
            if (flag) {
                for (int i = 0; i < level_num; ++i) {
                    auto node = deq.front();
                    deq.pop_front();
                    level[i] = node->val;
                    if (node->left) {
                        deq.push_back(node->left);
                    }
                    if (node->right) {
                        deq.push_back(node->right);
                    }
                }
            } else {
                for (int i = 0; i < level_num; ++i) {
                    auto node = deq.back();
                    deq.pop_back();
                    level[i] = node->val;
                    if (node->right) {
                        deq.push_front(node->right);
                    }
                    if (node->left) {
                        deq.push_front(node->left);
                    }
                }
            }
            flag = !flag;
            ans.push_back(level);
        }
        return ans;
    }
};