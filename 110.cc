#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return (getDepth(root) != -1);
    }

    int getDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = getDepth(root->left);
        if (left == -1) {
            return -1;
        }
        int right = getDepth(root->right);
        if (right == -1) { 
            return -1;
        }
        if (left > right) {
            return (left > right + 1) ? -1 : left + 1;
        }
        return (right > left + 1) ? -1 : right + 1;
    }
};