/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (auto i = nums.begin(); i != nums.end() && i != nums.end() - 1; ++i) {
            while (*(i + 1) == *i) {
                nums.erase(i + 1);
                if (i + 1 == nums.end()) {
                    break;
                }
            }
        }
        return nums.size();
    }
};*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};