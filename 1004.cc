#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {
            return 0;
        }
        
        int count = 1;
        int ans = numbers[0];
        int begin = -1;
        for (int i = 1; i < numbers.size(); i++) {
            count += ans == numbers[i];
            if ((count << 1) < i - begin) {
                count = 1;
                ans = numbers[i];
                begin = i - 1;
            }
        }
        
        count = 0;
        for (int i = 0; i < numbers.size(); i++) {
            count += numbers[i] == ans;
        }
        return (count << 1) > numbers.size() ? ans : 0;
    }
};

int main() {
    int arr[] = {1,2,3,2,2,2,5,4,2};
    vector<int> numbers(arr, arr + 9);
    cout << Solution().MoreThanHalfNum_Solution(numbers) << endl;
    return 0;
}