class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int start = 0;
        int ans = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == ans) {
                count++;
            }
            if ((count << 1) <= i - start) {
                start = i;
                ans = nums[i];
                count = 1;
            }
        }
        return ans;
    }
};