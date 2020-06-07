#include <iostream>
#include <vector>
#include <stack>

using namespace std;


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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* last_visited = nullptr;
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        while (!s.empty()) {
            cur = s.top();
            if (cur->right == nullptr || cur->right == last_visited) {
                ans.push_back(cur->val);
                s.pop();
                last_visited = cur;
            } else {
                cur = cur->right;
                while (cur) {
                    s.push(cur);
                    cur = cur->left;
                }
            }
        }
        return ans;
    }
};

int main() {
    auto root = new TreeNode(1);
    root->right = new TreeNode(2);
    // auto node = root->right;
    // node->left = new TreeNode(3);
    auto solution = Solution();
    solution.postorderTraversal(root);
    return 0;
}
