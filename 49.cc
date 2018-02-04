#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

/* class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> ans;
        vector<vector<string>> res;
        for (auto str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            ans[tmp].push_back(str);
        }
        for (auto iter = ans.begin(); iter != ans.end(); ++iter) {
            res.push_back(iter->second);
        }
        return res;
    }
}; */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        map<int, vector<string>> ans;
        vector<vector<string>> res;
        for (auto str: strs) {
            int tmp = 1;
            for (auto c: str) {
                tmp *= primes[c - 'a'];
            }
            ans[tmp].push_back(str);
        }
        for (auto iter = ans.begin(); iter != ans.end(); ++iter) {
            res.push_back(iter->second);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = solution.groupAnagrams(strs);
    return 0;
}