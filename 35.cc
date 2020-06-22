class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        int mid;
        while (begin <= end) {
            mid = (begin + end) >> 1;
            if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                begin = mid + 1;
            } else {
                return mid;
            }
        }
        return begin;
    }
};