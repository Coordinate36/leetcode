#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.empty()) {
            return res;
        }
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start;
        });

        int nowStart = intervals[0].start;
        int nowEnd = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            if (nowEnd >= intervals[i].start) {
                nowEnd = max(nowEnd, intervals[i].end);
            } else {
                res.push_back(Interval(nowStart, nowEnd));
                nowStart = intervals[i].start;
                nowEnd = intervals[i].end;
            }
        }
        res.push_back(Interval(nowStart, nowEnd));
        return res;
    }
};

int main() {
    Solution solution;
    vector<Interval> intervals = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    auto res = solution.merge(intervals);
    return 0;
}