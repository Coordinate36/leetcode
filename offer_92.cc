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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (n == 1) {
            return head;
        }
        ListNode *left_pre, *left;
        ListNode *pre, *cur, *next;
        if (m == 1) {
            left = pre = head;
        } else {
            left_pre = head;
            for (int i = 2; i < m; ++i) {
                left_pre = left_pre->next;
            }
            left = pre = left_pre->next;
        }
        cur = pre->next;
        for (int i = m; i < n; ++i) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        left->next = cur;
        if (m == 1) {
            head = pre;
        } else {
            left_pre->next = pre;
        }
        return head;
    }
};