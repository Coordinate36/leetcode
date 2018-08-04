#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        vector<int> ans;
        pathSum(res, ans, root, sum);
        return res;
    }

    void pathSum(vector<vector<int>> &res, vector<int> &ans, TreeNode* root, int sum) {
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == sum) {
                ans.push_back(sum);
                res.push_back(ans);
                ans.pop_back();
                return;
            }
        }
        ans.push_back(root->val);
        if (root->left) {
            pathSum(res, ans, root->left, sum - root->val);
        }
        if (root->right) {
            pathSum(res, ans, root->right, sum - root->val);
        }
        ans.pop_back();
    }
};