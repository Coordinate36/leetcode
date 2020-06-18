#include <iostream>
#include <unordered_map>


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        for (auto p = head; p != nullptr; p = p->next) {
            mp[p] = new Node(p->val);
        }
        for (auto p = head; p != nullptr; p = p->next) {
            if (p->next) {
                mp[p]->next = mp[p->next];
            }
            if (p->random) {
                mp[p]->random = mp[p->random];
            }
        }
        return mp[head];
    }
};