class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; ++i) {
            ans = recur(ans);
        }
        return ans;
    }

    string recur(string s) {
        string res = "";
        char last = s[0];
        int count = 1;
        int len = s.size();

        for (int i = 1; i < len; ++i) {
            if (s[i] == last) {
                ++count;
            } else {
                res = res + (char)(count + '0') + last;
                count = 1;
                last = s[i];
            }
        }

        res = res + (char)(count + '0') + last;

        return res;
    }
};