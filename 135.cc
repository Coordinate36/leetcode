class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < candies.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        for (int i = candies.size() - 1; i > 0; --i) {
            if (ratings[i-1] > ratings[i]) {
                candies[i-1] = max(candies[i-1], candies[i] + 1);
            }
        }
        return accumulate(candies.cbegin(), candies.cend(), 0);
    }
};