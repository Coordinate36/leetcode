class Solution {
public:
    string replaceSpace(string s) {
        stringstream ss;
        for (auto c : s) {
            if (c == ' ') {
                ss << "%20";
            }  else {
                ss << c;
            }
        }
        return ss.str();
    }
};