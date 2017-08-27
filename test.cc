int firstMissingPositive(int* nums, int numsSize) {
    int i, a;
    for(i = 0; i < numsSize; i++) {
        if(nums[i] < 0) {
            nums[i] = numsSize + 10;
        }
    }
    for(i = 0; i < numsSize; i++) {
        a = abs(nums[i]);
        if(a <= numsSize && a > 0) {
            nums[a - 1] = -nums[a - 1];
        }
    }
    for(i = 0; i < numsSize; i++) {
        if(nums[i]) {
            break;
        }
    }
    return i + 1;
}