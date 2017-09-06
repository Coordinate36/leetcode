/*class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (nums[i] >= target) {
                return i;
            }
        }
        return len;
    }
};*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};