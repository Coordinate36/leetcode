class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return nums;
        }
        int num1 = nums[0];
        int num2 = 0;
        int count1 = 1;
        int count2 = 0;
        vector<int> res;

        for (int i = 1; i < size; ++i) {
            if (nums[i] == num1) {
                ++count1;
            } else if (nums[i] == num2) {
                ++count2;
            } else if (count1 == 0) {
                num1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                num2 = nums[i];
                count2 = 1;
            } else {
                --count1;
                --count2;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int i = 0; i < size; ++i) {
            if (nums[i] == num1) {
                ++count1;
            } else if (nums[i] == num2) {
                ++count2;
            }
        }
        
        cout << size << " " << num1 << " " << num2 << endl;
        
        if (count1 > size / 3) {
            res.push_back(num1);
        }
        if (count2 > size / 3) {
            res.push_back(num2);
        }

        return res;
    }
};