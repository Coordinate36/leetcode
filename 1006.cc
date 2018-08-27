#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.empty()) {
            return false;
        }

        stack<int> s;
        int i = 0;
        for (auto elem : pushV) {
            s.push(elem);
            while (i < popV.size() && popV[i] == s.top()) {
                s.pop();
                i++;
            }
        }

        return s.empty();
    }
};