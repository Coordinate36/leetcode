#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode* node = head;
        int len = 1;
        for (; node->next != nullptr; node = node->next) {
            ++len;
        }
        node->next = head;
        k = len - (k % len);
        ListNode* node = head;
        for (int i = 1; i < k; ++i) {
            node = node->next;
        }
        ListNode* newHead = node->next;
        node->next = head;
        node->next = nullptr;
        return newHead;
    }
}; */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode* node = head;
        int len = 1;
        for (; node->next != nullptr; node = node->next) {
            ++len;
        }
        node->next = head;
        k = len - (k % len);
        for (int i = 0; i < k; ++i) {
            node = node->next;
        }
        ListNode* newHead = node->next;
        node->next = nullptr;
        return newHead;
    }
};

int main() {
    Solution solution;
    
    return 0;
}