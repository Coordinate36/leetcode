#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s(A.cbegin(), A.cend());
        vector<int> ans(A.size());
        for (int i = 0; i < B.size(); ++i) {
            auto iter = s.upper_bound(B[i]);
            if (iter == s.cend()) {
                iter = s.begin();
            }
            ans[i] = *iter;
            s.erase(iter);
        }
        return ans;
    }
};