class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int left = 1;
        int right = 2;
        int half = target >> 1;
        while (left < right && left <= half) {
            int sum = (left + right) * (right - left + 1) >> 1;
            if (sum == target) {
                vector<int> vec;
                for (int n = left; n <= right; ++n) {
                    vec.emplace_back(n);
                }
                ans.emplace_back(vec);
                ++left;
            } else if (sum < target) {
                ++right;
            } else {
                ++left;
            }
        }
        return ans;
    }
};