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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr) {
            return nullptr;
        }
        TreeNode *tail;
        return Convert(pRootOfTree, tail);
    }

    TreeNode* Convert(TreeNode* root, TreeNode* &tail) {
        TreeNode* head;

        if (root->left == nullptr) {
            head = root;
        } else {
            head = Convert(root->left, tail);
            tail->right = root;
            root->left = tail;
        }

        if (root->right == nullptr) {
            tail = root;
        } else {
            TreeNode* rHead = Convert(root->right, tail);
            root->right = rHead;
            rHead->left = root;
        }

        return head;
    }
};