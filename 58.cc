class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int l, r;
        for (r = s.size() - 1; r >= 0 && s[r] == ' '; --r);
        if (r < 0) {
            return 0;
        }
        for (l = r; l >= 0 && s[l] != ' '; --l);
        return r - l;
    }
};