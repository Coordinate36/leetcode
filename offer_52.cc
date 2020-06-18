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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        for (auto p = headA; p; p = p->next) {
            lenA++;
        }
        for (auto p = headB; p; p = p->next) {
            lenB++;
        }
        if (lenA > lenB) {
            for (int i = lenA; i > lenB; --i) {
                headA = headA->next;
            }
        } else {
            for (int i = lenB; i > lenA; --i) {
                headB = headB->next;
            }
        }
        auto pA = headA;
        auto pB = headB;
        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};