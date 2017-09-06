class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                res[0] = searchStart(nums, left, mid, target);
                res[1] = searchEnd(nums, mid, right, target);
                return res;
            }
        }
        res[0] = res[1] = -1;
        return res;
    }

    int searchStart(vector<int> nums, int begin, int end, int target) {
        int mid;
        while (begin < end) {
            mid = (begin + end) / 2;
            if (nums[mid] < target) {
                begin = mid + 1;
            } else {
                end = mid;
            } 
        }
        return begin;
    }

    int searchEnd(vector<int> nums, int begin, int end, int target) {
        int mid;
        while (begin < end) {
            mid = (begin + end + 1) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid;
            }
        }
        return begin;
    }
};

