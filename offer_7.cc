#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        return _buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int lb, int le, int rb, int re) {
        if (lb > le) {
            return nullptr;
        }
        auto root = new TreeNode(preorder[lb]);
        int new_re = rb;
        for (; new_re <= re; ++new_re) {
            if (inorder[new_re] == preorder[lb]) {
                break;
            }
        }
        new_re--;
        int new_le = new_re - rb + lb + 1;
        root->left = _buildTree(preorder, inorder, lb + 1, new_le, rb, new_re);
        root->right = _buildTree(preorder, inorder, new_le + 1, le, new_re + 2, re);
        return root;
    }
};


int main() {
    vector<int> preorder = vector<int>{3,9,20,15,7};
    vector<int> inorder = vector<int>{9,3,15,20,7};
    auto solution = Solution();
    solution.buildTree(preorder, inorder);
    return 0;
}
