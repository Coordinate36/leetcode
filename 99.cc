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

// class Solution {
// public:
//     void recoverTree(TreeNode* root) {
//         vector<TreeNode*> nodes;
//         vector<int> values;
//         traverse(root, nodes, values);
//         int left_idx = -1;
//         int right_idx = -1;
//         for (int i = 0; i < values.size() - 1; ++i) {
//             if (values[i+1] < values[i]) {
//                 if (left_idx == -1) {
//                     left_idx = i;
//                 }
//                 right_idx = i + 1;
//             }
//         }
//         swap(values[left_idx], values[right_idx]);
//         for (int i = 0; i < nodes.size(); ++i) {
//             nodes[i]->val = values[i];
//         }
//     }

//     void traverse(TreeNode* root, vector<TreeNode*> &nodes, vector<int> &values) {
//         stack<TreeNode*> s;
//         TreeNode* p = root;
//         while (!s.empty() || p) {
//             if (p) {
//                 s.push(p);
//                 p = p->left;
//             } else {
//                 p = s.top();
//                 s.pop();
//                 nodes.push_back(p);
//                 values.push_back(p->val);
//                 p = p->right;
//             }
//         }
//     }
// };

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* lNode = nullptr;
        TreeNode* rNode = nullptr;
        TreeNode* lastNode = nullptr;
        traverse(root, lNode, rNode, lastNode);
        swap(lNode->val, rNode->val);
    }

    void traverse(TreeNode* root, TreeNode* &lNode, TreeNode* &rNode, TreeNode* &lastNode) {
        if (root->left) {
            traverse(root->left, lNode, rNode, lastNode);
        }
        if (lastNode && lastNode->val > root->val) {
            if (lNode == nullptr) {
                lNode = lastNode;
            }
            rNode = root;
        }
        lastNode = root;
        if (root->right) {
            traverse(root->right, lNode, rNode, lastNode);
        }
    }
};