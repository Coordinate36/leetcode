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

/* class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }
        int k;
        for (k = 0; k < intervals.size() && intervals[k].start < newInterval.start; ++k);
        if (k == intervals.size()) {
            res = intervals;
            if (intervals[k - 1].end >= newInterval.start) {
                res[k - 1].end = max(res[k - 1].end, newInterval.end);
            } else {
                res.push_back(newInterval);
            }
            return res;
        }
        for (int i = 0; i < k - 1; ++i) {
            res.push_back(intervals[i]);
        }
        if (k != 0) {
            if (intervals[k - 1].end >= newInterval.start) {
                newInterval.start = intervals[k - 1].start;
                newInterval.end = max(intervals[k - 1].end, newInterval.end);
            } else {
                res.push_back(intervals[k - 1]);
            }
        }
        int m;
        for (m = k; m < intervals.size() && intervals[m].start <= newInterval.end; ++m);
        newInterval.end = max(newInterval.end, intervals[m - 1].end);
        res.push_back(newInterval);
        for (int i = m; i < intervals.size(); ++i) {
            res.push_back(intervals[i]);
        }
        return res;
    }
}; */

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        bool inserted = false;
        for (auto iv : intervals) {
            if (iv.end < newInterval.start) {
                res.push_back(iv);
            } else if (iv.start > newInterval.end) {
                if (!inserted) {
                    res.push_back(newInterval);
                    inserted = true;
                }
                res.push_back(iv);
            } else {
                newInterval.start = min(newInterval.start, iv.start);
                newInterval.end = max(newInterval.end, iv.end);
            }
        }
        if (!inserted) {
            res.push_back(newInterval);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<Interval> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    Interval newInterval = {4, 9};
    // vector<Interval> intervals = {{1, 3}, {6, 9}};
    // vector<Interval> intervals = {};
    // Interval newInterval = {2, 5};
    auto res = solution.insert(intervals, newInterval);
    return 0;
}