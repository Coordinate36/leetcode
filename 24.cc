/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *fast, *slow, *mid;
        fast = head->next;
        head->next = fast->next;
        fast->next = head;
        head = fast;

        slow = head->next;
        mid = slow->next;
        
        while (mid != nullptr && mid->next != nullptr) {
            fast = mid->next;

            mid->next = fast->next;
            fast->next = mid;
            slow->next = fast;

            slow = mid;
            mid = mid->next;
        }

        return head;
    }
};*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *pre, *cur;
        cur = head->next;
        head->next = cur->next;
        cur->next = head;
        head = cur;

        pre = head->next;
        cur = pre->next;

        while (cur != nullptr && cur->next != nullptr) {
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = cur;

            pre = cur;
            cur = cur->next;
        }

        return head;
    }
};