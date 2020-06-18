class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        stack<Node*> st;
        Node* p = root;
        Node* last = nullptr;
        Node* head = nullptr;
        while (!st.empty() || p) {
            if (p) {
                st.push(p);
                p = p->left;
            } else {
                p = st.top();
                st.pop();
                if (head == nullptr) {
                    head = p;
                }
                if (last) {
                    last->right = p;
                    p->left = last;
                }
                last = p;
                p = p->right;
            }
        }
        last->right = head;
        head->left = last;
        return head;
    }
};