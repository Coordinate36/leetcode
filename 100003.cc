#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<pair<int, int>> &intervals) {
    sort(intervals.begin(), intervals.end(), 
        [](pair<int, int> x, pair<int, int> y) {
            return y.second > x.second;
        });

    int max_right = 0;
    int ans = 0;
    
    for (auto interval : intervals) {
        if (interval.first >= max_right) {
            ans += 1;
            max_right = interval.second;
        }
    }

    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> intervals;
    int s, t;
    while (N--) {
        cin >> s >> t;
        intervals.push_back(make_pair(s, t));
    }
    cout << solution(intervals) << endl;
    return 0;
}