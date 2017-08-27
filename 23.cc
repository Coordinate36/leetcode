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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return merge(lists, 0, lists.size() - 1);   
    }

    ListNode* merge(vector<ListNode*>& lists, int begin, int end) {
        if (begin == end) {
            return lists[begin];
        }
        int mid = (begin + end) / 2;
        ListNode *left = merge(lists, begin, mid);
        ListNode *right = merge(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *tail;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        tail = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
        return head;
    }
};