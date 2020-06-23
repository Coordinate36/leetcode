class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.length() < p.length()) {
            return ans;
        }
        int s_map[26] = {0}, p_map[26] = {0};
        for (int i = 0; i < p.length(); ++i) {
            s_map[s[i]-'a']++;
            p_map[p[i]-'a']++;
        }
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            count += s_map[i] == p_map[i];
        }
        int len_diff = s.length() - p.length();
        for (int i = 0; i < len_diff; ++i) {
            if (count == 26) {
                ans.push_back(i);
            }
            int l = s[i] - 'a', r = s[i+p.length()] - 'a';
            s_map[l]--;
            if (s_map[l] == p_map[l]) {
                ++count;
            } else if (s_map[l] == p_map[l] - 1) {
                --count;
            }
            s_map[r]++;
            if (s_map[r] == p_map[r]) {
                ++count;
            } else if (s_map[r] == p_map[r] + 1) {
                --count;
            }
        }
        if (count == 26) {
            ans.push_back(len_diff);
        }
        return ans;
    }
};