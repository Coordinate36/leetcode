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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        int nodeSize = sizeof(ListNode);
        ListNode* res = new ListNode(nodeSize);
        ListNode* p1;
        ListNode* p2;
        ListNode* q1 = res;
        ListNode* q2 = res;
        for (p1 = l1, p2 = l2; p1 && p2; p1 = p1->next, p2 = p2->next) {
            int sum = p1->val + p2->val + flag;
            flag = sum >= 10;
            q2->val = flag ? (sum - 10): sum;
            q1 = q2;
            q2 = new ListNode(nodeSize);
            q1->next = q2;
        }
        for (; p1; p1 = p1->next) {
            int sum = p1->val + flag;
            flag = sum >= 10;
            q2->val = flag ? (sum - 10): sum;
            q1 = q2;
            q2 = new ListNode(nodeSize);
            q1->next = q2;
        }
        for (; p2; p2 = p2->next) {
            int sum = p2->val + flag;
            flag = sum >= 10;
            q2->val = flag ? (sum - 10): sum;
            q1 = q2;
            q2 = new ListNode(nodeSize);
            q1->next = q2;
        }
        if (flag) {
            q2->val = 1;
            q2->next = NULL;
        } else {
            q1->next = NULL;
        }
        return res;
    }
};