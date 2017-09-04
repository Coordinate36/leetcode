class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordNum = words.size();
        int wordLen = words[0].size();
        int windowLen = wordLen * wordNum;
        int sLen = s.size();

        map<string, int> Map;

        for (int i = 0; i < wordNum; ++i) {
            ++Map[words[i]];
        }

        for (int i = 0; i < wordLen; ++i) {
            int count = 0;
            map<string, int> curMap;
            int left = i;

            for (int j = left; (j + wordLen <= sLen) && (left + windowLen <= sLen); j += wordLen) {
                string word = s.substr(j, wordLen);
                if (Map[word] == 0) {
                    count = 0;
                    curMap.clear();
                    left = j + wordLen;
                } else {
                    ++curMap[word];
                    if (curMap[word] <= Map[word]) {
                        ++count;
                        if (count == wordNum) {
                            res.push_back(left);
                            string tmp = s.substr(left, wordLen);
                            --curMap[tmp];
                            left += wordLen;
                            --count;
                        }
                    } else {
                        for (;;) {
                            string tmp = s.substr(left, wordLen);
                            left += wordLen;
                            --curMap[tmp];
                            if (tmp == word) {
                                break;
                            } else {
                                --count;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};