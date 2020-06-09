/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) {
            return head->next;
        }
        auto pre = head;
        auto cur = head->next;
        while (cur != nullptr && cur->val != val) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        return head;
    }
};