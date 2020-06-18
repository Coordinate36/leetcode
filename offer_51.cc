class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }

    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return 0;
        }
        int mid = (left + right) >> 1;
        int revertNum = mergeSort(nums, left, mid);
        revertNum += mergeSort(nums, mid + 1, right);
        int i = left, j = mid + 1;
        int tmp[right - left + 1];
        int k = 0;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                revertNum += j - mid - 1;
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            revertNum += j - mid - 1;
            tmp[k++] = nums[i++];
        }
        while (j <= right) {
            tmp[k++] = nums[j++];
        }
        for (i = left; i <= right; ++i) {
            nums[i] = tmp[i-left];
        }
        return revertNum;
    }
};