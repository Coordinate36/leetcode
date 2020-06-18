// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         auto lower_iter = lower_bound(nums.cbegin(), nums.cend(), target);
//         auto upper_iter = upper_bound(lower_iter, nums.cend(), target);
//         return distance(lower_iter, upper_iter);
//     }
// };

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int right = upper_bound(nums, 0, nums.size() - 1, target);
        int ans = 0;
        for (int i = right - 1; i >= 0 && nums[i] == target; --i) {
            ans++;
        }
        return ans;
    }

    int upper_bound(vector<int>& nums, int begin, int end, int target) {
        while (begin < end) {
            int mid = (begin + end) >> 1;
            if (nums[mid] <= target) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        return nums[begin] == target ? begin + 1 : begin;
    }
};