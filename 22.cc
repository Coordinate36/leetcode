/*class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string ans(n << 1, '(');
        generateParenthesis(n, 0, 0, ans);
        return res;
    }
    void generateParenthesis(int n, int count, int begin, string ans) {
        if (count == n) {
            res.push_back(ans);
            return;
        }

        for (int i = begin; i <= n + count; ++i) {
            if ((count << 1) < i) {
                ans[i] = ')'; 
                generateParenthesis(n, count + 1, i + 1, ans);
                ans[i] = '(';
            }
        }
    }
};*/

/*class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string ans(n << 1, '(');
        generateParenthesis(n, 0, 0, ans);
        return res;
    }
    void generateParenthesis(int n, int count, int begin, string ans) {
        if (count == n) {
            res.push_back(ans);
            return;
        }

        if (begin < count + n) {
            generateParenthesis(n, count, begin + 1, ans);
        }
        if ((count << 1) < begin) {
            ans[begin] = ')'; 
            generateParenthesis(n, count + 1, begin + 1, ans);
            ans[begin] = '(';
        }
    }
};*/

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return res;
        }
        generate(0, 0, n, "");
        return res;
    }
    void generate(int left, int right, int n, string ans) {
        if (right == n) {
            result.push_back(ans);
        }

        if (left < n) {
            generate(left + 1, right, n, ans + '(');
        }
        if (right < left) {
            generate(left, right + 1, n, ans + ')');
        }
    }
};