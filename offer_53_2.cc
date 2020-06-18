class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid = (begin + end) >> 1;
        while (begin <= end) {
            if (nums[mid] == mid) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
            mid = (begin + end) >> 1;
        }
        return begin;
    }
};