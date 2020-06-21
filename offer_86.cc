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
    ListNode* partition(ListNode* head, int x) {
        auto left = new ListNode(-1);
        auto right = new ListNode(-1);
        auto left_tail = left;
        auto right_tail = right;
        for (auto p = head; p; p = p->next) {
            if (p->val < x) {
                left_tail->next = p;
                left_tail = p;
            } else {
                right_tail->next = p;
                right_tail = p;
            }
        }
        left_tail->next = right->next;
        right_tail->next = nullptr;
        return left->next;
    }
};