#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = {0};
        int mask[26] = {0};
        for (auto c : s) {
            count[c-'a']++;
        }
        stringstream stream;
        int pos = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (mask[s[i]-'a']) {
                continue;
            }
            if (s[pos] > s[i]) {
                pos = i;
            }
            if (--count[s[i]-'a'] == 0) {
                stream << s[pos];
                mask[s[pos]-'a'] = 1;
                for (int j = pos+1; j <= i; ++j) {
                    count[s[j]-'a']++;
                }
                while (++pos < s.size() && mask[s[pos]-'a']);
                i = pos - 1;
            }
        }
        return stream.str();
    }
};


int main() {
    auto solution = Solution();
    cout << solution.removeDuplicateLetters("cbacdcbc") << endl;
    return 0;
}