#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool isNumber(string s) {
        int start = 0;
        int end = s.length() - 1;
        while (start <= end && s[start] == ' ') {
            ++start;
        }
        while (start <= end && s[end] == ' ') {
            --end;
        }
        if (start > end) {
            return false;
        }
        const char* c_str = s.c_str();
        for (auto i = start + 1; i < end; ++i) {
            if (s[i] == 'e') {
                int left_start = int(s[start] == '+' || s[start] == '-') + start;
                int right_start = int(s[i+1] == '+' || s[i+1] == '-') + i + 1;
                return isDecimal(c_str, left_start, i - 1) && isInteger(c_str, right_start, end);
            }
        }
        start += int(s[start] == '+' || s[start] == '-');
        return isDecimal(c_str, start, end);
    }

    bool isDecimal(const char* s, unsigned int begin, unsigned int end) {
        for (auto i = begin; i <= end; ++i) {
            if (s[i] == '.') {
                return end > begin && (i == begin || isInteger(s, begin, i - 1)) && (i == end || isInteger(s, i + 1, end));
            }
        }
        return isInteger(s, begin, end);
    }

    bool isInteger(const char* s, unsigned int begin, unsigned int end) {
        if (begin > end) {
            return false;
        }
        for (auto i = begin; i <= end; ++i) {
            if (s[i] > '9' || s[i] < '0') {
                return false;
            }
        }
        return true;
    }
};


int main() {
    auto test_cases = vector<string>{"..", " 4e+", ".1", "0.", "1.e10", "0", " 0.1 ", "abc", "1 a", "2e10", " -90e3   ", " 1e", "e3", " 6e-1", " 99e2.5 ", "53.5e93", " --6 ", "-+3", "95a54e53"};
    auto solution = Solution();
    for (auto s : test_cases) {
        cout << s << " " << solution.isNumber(s) << endl;
    }
    return 0;
}
