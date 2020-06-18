class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int ans = 0;
        int max_ = INT_MIN;
        int min_ = INT_MAX;
        for (auto price : prices) {
            if (price > max_) {
                max_ = price;
                ans = max(ans, max_ - min_);
            }
            if (price < min_) {
                min_ = price;
                max_ = price;
            }
        }
        return ans;
    }
};