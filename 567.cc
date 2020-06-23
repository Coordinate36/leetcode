class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) {
            return false;
        }
        int s1map[26] = {0}, s2map[26] = {0};
        int count = 0;
        for (int i = 0; i < s1.length(); ++i) {
            s1map[s1[i]-'a']++;
            s2map[s2[i]-'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            count += s1map[i] == s2map[i];
        }
        for (int i = 0; i < s2.length() - s1.length(); ++i) {
            if (count == 26) {
                return true;
            }
            int l = s2[i] - 'a';
            int r = s2[i+s1.length()] - 'a';
            s2map[l]--;
            s2map[r]++;
            if (s2map[l] == s1map[l]) {
                ++count;
            } else if (s2map[l] == s1map[l] - 1) {
                --count;
            }
            if (s2map[r] == s1map[r]) {
                ++count;
            } else if (s2map[r] == s1map[r] + 1) {
                --count;
            }
        }
        return count == 26;
    }
};