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
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        for (auto p = head; p != nullptr; p = p->next) {
            ans.push_back(p->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};