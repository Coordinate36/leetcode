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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }

        ListNode *pre, *h, *t, *next;
        
        h = head;
        t = head;
        for (int i = 0; i < k - 1; ++i) {
            t = t->next;
            if (t == nullptr) {
                return head;
            }
        }
        next = t->next;
        reserse(h, k);
        h->next = next;
        head = t;

        for(;;) {
            pre = h;
            h = next;
            for (int i = 0; i < k - 1; ++i) {
                if (next == nullptr) {
                    return head;
                }
                next = next->next;
            }
            if (next == nullptr) {
                return head;
            }
            t = next;
            next = next->next;
            pre->next = t;
            reserse(h, k);
            h->next = next;
        }
    }

    void reserse(ListNode *head, int k) {
        ListNode *tail, *second;
        second = head->next;
        tail = second;
        for (int i = 0; i < k - 2; ++i) {
            head->next = tail->next;
            tail->next = tail->next->next;
            head->next->next = second;
            second = head->next;
        }
        tail->next = head;
    }
};