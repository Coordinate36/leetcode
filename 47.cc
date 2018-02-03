class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back(nums);

        int m, k;
        bool flag = true;
        for(;;) {
            flag = false;
            for (m = size - 1; m > 0; --m) {
                if (nums[m] > nums[m - 1]) {
                    flag = true;
                    break;
                }
            }
            --m;
            if (flag) {
                for (k = m + 1; (k < size - 1) && (nums[k + 1] > nums[m]); ++k);
                swap(nums[m], nums[k]);
                auto iter = nums.begin();
                iter += m + 1;
                reverse(iter, nums.end());
                vector<int> tmp;
                for (int i = 0; i < size; ++i) {
                    tmp.push_back(nums[i]);
                }
                res.push_back(tmp);
            } else {
                break;
            }
        }
        return res;
    }
};