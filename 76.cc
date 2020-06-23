class Solution {
public:
    bool check(unordered_map<char, int>& ori, unordered_map<char, int>& cnt) {
        for (auto& p : ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> ori, cnt;
        for (auto& c : t) {
            ori[c]++;
        }
        int l = 0, r = 0;
        for (; r < s.length(); ++r) {
            if (ori.find(s[r]) != ori.cend()) {
                cnt[s[r]]++;
            }
            if (check(ori, cnt)) {
                break;
            }
        }
        int best_l = l, best_r = r;
        while (r < s.length()) {
            while (l <= r) {
                if (ori.find(s[l]) != ori.cend()) {
                    if (cnt[s[l]] <= ori[s[l]]) {
                        break;
                    }
                    cnt[s[l]]--;
                }
                ++l;
            }
            if (r - l < best_r - best_l) {
                best_l = l;
                best_r = r;
            }
            if (r - l < t.length()) {
                break;
            }
            if (ori.find(s[++r]) != ori.cend()) {
                cnt[s[r]]++; 
            }
        }
        return best_r == s.length() ? "" : s.substr(best_l, best_r - best_l + 1);
    }
};