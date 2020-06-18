#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> data;
    stack<int> desc;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        if (desc.empty() || x <= desc.top()) {
            desc.push(x);
        }
    }
    
    void pop() {
        int v = data.top();
        data.pop();
        if (v == desc.top()) {
            desc.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int min() {
        return desc.top();
    }
};


int main() {
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.min() << endl;   // 返回 -3.
    minStack.pop();
    cout << minStack.top() << endl;      // 返回 0.
    cout << minStack.min() << endl;   // 返回 -2.
    return 0;
}