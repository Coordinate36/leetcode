#include <algorithm>
#include <iostream>
#include <map>
#include <cstdio>
#include <string>
#include <typeinfo>
#include <vector>
#include <stack>
using namespace std;

double max(double a, double b) {
    return a > b ? a: b;
}

double findMaxDis(vector<double> &nums, int left, int right, double maxDis) {
    double tmp = nums[right] - nums[left];
    if (tmp > 180.0) {
        for (int i = left; (nums[right] - nums[i]) >= 180.0; ++i) {
            int j;
            for (j = right; (nums[j] - nums[i]) > 180.0; --j);
            maxDis = max(maxDis, (360 - nums[j + 1] + nums[i]));
            maxDis = max(maxDis, nums[j] - nums[i]);
            maxDis = max(maxDis, nums[j + 1] - nums[i + 1]);
        }
        ++i;
        maxDis = max(maxDis, )
    } else {
        maxDis = max(maxDis, tmp);
    }
    return maxDis;
}

int main()
{
    int n;
    cin >> n;
    vector<double> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    printf("%.8f\n", findMaxDis(nums, 0, n - 1, 0));
    return 0;
}

