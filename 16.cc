class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        int diff = INT_MAX;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1; 
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    ans = sum;
                }

                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    return sum;
                }
            }
        }
        return ans;
    }
};