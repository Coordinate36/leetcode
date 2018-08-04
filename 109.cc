#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, nullptr);
    }
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return nullptr;
        }
        if (head->next == tail) {
            TreeNode *node = new TreeNode(head->val);
            return node;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != tail && fast->next->next != tail) {
            cout << fast->val << " ";
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << fast->val << endl;
        TreeNode *node = new TreeNode(slow->val);
        node->left = sortedListToBST(head, slow);
        node->right = sortedListToBST(slow->next, tail);
        return node;
    } 
};