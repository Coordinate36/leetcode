class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0) {
            return "";
        }
        int length = strs[0].size();
        for (int i = 0; i < length; ++i) {
            char c = strs[0][i];
            for (int j = 0; j < size; ++j) {
                if (c != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

/*class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0) {
            return "";
        }
        return longestCommonPrefix(strs, 0, size - 1);
    }
    string longestCommonPrefix(vector<string>& strs, int l, int r) {
        if (l == r) {
            return strs[l];
        }
        int mid = (l + r) / 2;
        string leftCommenPrefix = longestCommonPrefix(strs, l, mid);
        string rightCommenPrefix = longestCommonPrefix(strs, mid + 1, r);
        return CommentPrefix(leftCommenPrefix, rightCommenPrefix);
    }
    string CommentPrefix(string left, string right) {
        int minLength = min(left.size(), right.size());
        for (int i = 0; i < minLength; ++i) {
            if (left[i] != right[i]) {
                return left.substr(0, i);
            }
        }
        return left.substr(0, minLength);
    }
};
*/
