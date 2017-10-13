class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<int>> isPalind(len, vector<int>(len, false));
        vector<vector<int>> palindEnd(len);

        for (int i = 0; i < len; ++i) {
            isPalind[i][i] = true;
            palindEnd[i].push_back(i);
        }

        for (int i = 1; i < len; ++i) {
            if (s[i - 1] == s[i]) {
                isPalind[i - 1][i] = true;
                palindEnd[i - 1].push_back(i);
            }
        }

        for (int i = 2; i < len; ++i) {
            for (int j = 0; i + j < len; ++j) {
                if (isPalind[j + 1][j + i - 1] && s[j] == s[j + i]) {
                    isPalind[j][j + i] = true;
                    palindEnd[j].push_back(j + i);
                }
            }
        }

        vector<string> ans;

        recur(palindEnd, ans, s, 0);

        return res;
    }

    void recur(vector<vector<int>> &palindEnd, vector<string> &ans, string &s, int begin) {
        if (begin == s.size()) {
            res.push_back(ans);
            return;
        }
        int len = palindEnd[begin].size();
        for (int i = 0; i < len; ++i) {
            ans.push_back(s.substr(begin, palindEnd[begin][i] - begin + 1));
            recur(palindEnd, ans, s, palindEnd[begin][i] + 1);
            ans.pop_back();
        }
    }
};