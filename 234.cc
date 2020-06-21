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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        auto slow = head;
        auto fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto right = reverseList(slow->next);
        auto l = head, r = right;
        for (; r; r = r->next) {
            if (l->val != r->val) {
                break;
            }
            l = l->next;
        }
        slow->next = reverseList(right);
        return r == nullptr;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto pre = head, cur = head->next;
        ListNode* next;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = nullptr;
        return pre;
    }
};