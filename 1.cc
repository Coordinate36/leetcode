class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numMap;
        vector<int> result;
        for (int i = 0; i != nums.size(); ++i) {
            numMap[nums[i]] = i;
        }
        for (int i = 0; i != nums.size(); ++i) {
            if (numMap[target - nums[i]]) {
                result.push_back(i);
                result.push_back(numMap[target - nums[i]]);
                return result;
            }
        }
    }
};