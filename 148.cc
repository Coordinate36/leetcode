/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* h1, struct ListNode* h2) {
	if (h1 == NULL) {
		return h2;
	}
	if (h2 == NULL) {
		return h1;
	}
    struct ListNode* t;
    if (h1->val < h2->val) {
    	t = h1;
    	h1 = h1->next;
    }
    else {
    	t = h2;
    	h2 = h2->next;
    }
    struct ListNode* head = t;
    while (h1 && h2) {
    	if (h1->val < h2->val) {
    		t->next = h1;
    		h1 = h1->next;
    	}
    	else {
    		t->next = h2;
    		h2 = h2->next;
    	}
    	t = t->next;
    }
    if (h1) {
    	t->next = h1;
    }
    else {
    	t->next = h2;
    }
    return head;
}
struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
    	return head;
    }
    struct ListNode* fast, *slow;
    struct ListNode* result;
    fast = slow = head;
    if (head) {
    	slow = slow->next;
    }
    while (slow && slow->next) {
    	fast = fast->next;
    	slow = slow->next->next;
    } 
    slow = fast->next;
    fast->next = NULL;
    fast = sortList(head);
    slow = sortList(slow);
    result = merge(fast, slow);
    return result;
}