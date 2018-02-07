#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for (int i = 1; i <= n; ++i) {
            s += i + '0';
        }
        for (int i = 1; i < k; ++i) {
            permutate(s);
        }
        return s;
    }

    void permutate(string &s) {
        int m;
        for (m = s.size() - 1; m > 0 && s[m - 1] >= s[m]; --m);
        if (m == 0) {
            return;
        }
        --m;
        int k;
        for (k = m + 1; k < s.size() && s[k] > s[m]; ++k);
        swap(s[m], s[k - 1]);
        auto iter = s.begin();
        iter += m + 1;
        reverse(iter, s.end());
    }
}; */

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n, 1);
        vector<int> index(n, 1);
        string res;
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
            index[i] = i + 1;
        }
        --k;
        for (int i = n - 1; i >= 0; --i) {
            int pos = k / factorial[i];
            k -= factorial[i] * pos;
            res += to_string(index[pos]);
            index.erase(index.begin() + pos);
        }
        return res;
    }
};

int main() {
    Solution solution;
    auto res = solution.getPermutation(3, 4);
    cout << res << endl;
    return 0;
}