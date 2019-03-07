#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        set<pair<int, int>> vects;
        vector<pair<int, int>> ans;
        for (auto rect : buildings) {
            vects.insert(make_pair(rect[0], -rect[2]));
            vects.insert(make_pair(rect[1], rect[2]));
        }
        multiset<int> heights{0};
        int maxHeight = 0;
        for (auto vect : vects) {
            if (vect.second < 0) {
                heights.insert(-vect.second);
            } else {
                heights.erase(heights.find(vect.second));
            }
            if (maxHeight != *(heights.rbegin())) {
                maxHeight = *(heights.rbegin());
                ans.push_back(make_pair(vect.first, maxHeight));
            }
        }
        return ans;
    }
};