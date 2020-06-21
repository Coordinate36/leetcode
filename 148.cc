/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if (head == nullptr) {
//             return head;
//         }
//         ListNode* tail = head;
//         for (; tail->next; tail = tail->next);
//         quickSort(head, tail);
//         return head;
//     }

//     void quickSort(ListNode* head, ListNode* tail) {
//         if (head == tail) {
//             return;
//         }
//         if (head->next == tail) {
//             if (head->val > tail->val) {
//                 swap(head->val, tail->val);
//             }
//             return;
//         }
//         selectPrior(head, tail);
//         auto pos = partition(head, tail);
//         quickSort(head, pos);
//         quickSort(pos->next, tail);
//     }

//     ListNode* partition(ListNode* head, ListNode* tail) {
//         auto pre = head;
//         for (auto cur = head; cur != tail; cur = cur->next) {
//             if (cur->val < tail->val) {
//                 swap(pre->val, cur->val);
//                 pre = pre->next;
//             }
//         }
//         swap(pre->val, tail->val);
//         return pre;
//     }

//     void selectPrior(ListNode* head, ListNode* tail) {
//         auto three = head->next;
//         if (head->val > three->val) {
//             if (three->val > tail->val) {
//                 swap(three->val, tail->val);
//             } else if (tail->val > head->val) {
//                 swap(tail->val, head->val);
//             }
//         } else {
//             if (head->val > tail->val) {
//                 swap(head->val, tail->val);
//             } else if (tail->val > three->val) {
//                 swap(tail->val, three->val);
//             }
//         }
//     }
// };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto slow = head;
        auto fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto mid = slow->next;
        slow->next = nullptr;
        auto left = sortList(head);
        auto right = sortList(mid);
        ListNode* new_head;
        if (left->val < right->val) {
            new_head = left;
            left = left->next;
        } else {
            new_head = right;
            right = right->next;
        }
        auto tail = new_head;
        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if (left) {
            tail->next = left;
        } else {
            tail->next = right;
        }
        return new_head;
    }
};