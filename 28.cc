/*class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        return haystack.find(needle);
    }
};*/


// KMP算法
/*class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int next[needle.size()];
        getNext(needle, next);
        int i = 0;
        int j = 0;
        int sLen = haystack.size();
        int pLen = needle.size();
        while (i < sLen && j < pLen) {
            // j == -1 说明 needle[0] != haystack[i]，则从 needle 的第0项开始跟haystack的下一项开始比较
            // next[j] 的前 next[j] 项与 needle[j] 之前的 next[j] 项匹配
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        if (j == needle.size()) {
            return i - j;
        } else {
            return -1;
        }
    }

    void getNext(string p, int next[]) {
        next[0] = -1;
        int i = 0;
        int j = -1;
        while (i < p.size() - 1) {
            if (j == -1 || p[i] == p[j]) {
                ++i;
                ++j;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
    }
};*/

// BM算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        int i = 0;
        int j = 0;
        int pLen = needle.size();
        int sLen = haystack.size();

        while ()
    }
};