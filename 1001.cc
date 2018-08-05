#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        vector<int> ans;
        dfs(res, ans, root, 0, expectNumber);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &ans, TreeNode* node, int cur, int expectNumber) {
        cur += node->val;
        if (cur > expectNumber) {
            return;
        }
        ans.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr && cur == expectNumber) {
            res.push_back(ans);
        }

        if (node->left != nullptr) {
            dfs(res, ans, node->left, cur, expectNumber);
        }
        if (node->right != nullptr) {
            dfs(res, ans, node->right, cur, expectNumber);
        }

        ans.pop_back();
    }
};