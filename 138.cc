/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (auto p = head; p;) {
            auto clone = new Node(p->val);
            clone->next = p->next;
            p->next = clone;
            p = clone->next;
        }
        for (auto p = head; p; p = p->next->next) {
            p->next->random = p->random ? p->random->next : nullptr;
        }
        auto new_head = head->next;
        for (auto p = head; p; p = p->next) {
            auto clone = p->next;
            p->next = clone->next;
            clone->next = clone->next ? clone->next->next : nullptr;
        }
        return new_head;
    }
};