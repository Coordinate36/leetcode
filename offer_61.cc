class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int mp[14] = {0};
        int lower = 13;
        int upper = 1;
        for (auto n : nums) {
            if (n) {
                if (mp[n]) {
                    return false;
                }
                lower = min(lower, n);
                upper = max(upper, n);
                mp[n] = 1;
            }
        }
        return (upper - lower < 5);
    }
};