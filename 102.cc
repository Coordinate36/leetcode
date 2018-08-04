#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> q1, q2;
        q1.push(root);
        while (true) {
            if (move_on(q1, q2, ans)) {
                return ans;
            }
            if (move_on(q2, q1, ans)) {
                return ans;
            }
        }
    }

    bool move_on(queue<TreeNode*> &q1, queue<TreeNode*> &q2, vector<vector<int>> &ans) {
        vector<int> vec;
        TreeNode* tmp;
        while (!q1.empty()) {
            tmp = q1.front();
            if (tmp->left)
                q2.push(tmp->left);
            if (tmp->right)
                q2.push(tmp->right);
            vec.push_back(tmp->val);
            q1.pop();
        }
        ans.push_back(vec);
        return q2.empty();
    }
};

int main() {
    queue<int> q;
    q.push(1);
    q.pop();
    cout << (q.empty()) << endl;
    return 0;
}