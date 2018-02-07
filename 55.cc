#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        int end = nums.size() - 1;
        while (maxi + nums[maxi] < end) {
            int tmp_maxi = maxi;
            for (int i = maxi + 1; i <= maxi + nums[maxi]; ++i) {
                if (i + nums[i] > tmp_maxi + nums[tmp_maxi]) {
                    tmp_maxi = i;
                }
            }
            if (tmp_maxi == maxi) {
                return false;
            }
            maxi = tmp_maxi;
        }
        return true;
    }
}; */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPos = nums[0];
        for (int i = 0; i <= lastPos; ++i) {
            if (i + nums[i] > lastPos) {
                lastPos = i + nums[i];
            }
            if (lastPos >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,2,1,0,4};
    cout << solution.canJump(nums) << endl;
    return 0;
}