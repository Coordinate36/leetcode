#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); ++i)
        {
            inMap[inorder[i]] = i;
        }
        return buildTree_(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inMap);
    }

    TreeNode *buildTree_(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int> &inMap)
    {
        if (preStart > preEnd)
        {
            return nullptr;
        }
        auto root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;
        root->left = buildTree_(preorder, inorder, preStart + 1, preStart + numsLeft, inStart, inRoot - 1, inMap);
        root->right = buildTree_(preorder, inorder, preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd, inMap);
        return root;
    }
};

int main()
{
    auto solution = Solution();
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    solution.buildTree(preorder, inorder);
}