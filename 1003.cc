#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k == 0 || input.size() < k) {
            return vector<int>();
        }
        vector<int> maxHeap(k);
        for (int i = 0; i < k; i++) {
            maxHeap[i] = input[i];
        }
        
        createHeap(maxHeap, k);
        
        for (int i = k; i < input.size(); i++) {
            if (maxHeap[0] > input[i]) {
                maxHeap[0] = input[i];
                heapify(maxHeap, k, 0);
            }
        }

        return maxHeap;
    }
    
    void heapify(vector<int> &maxHeap, int k, int i) {
        int lChild;
        int rChild;
        int maxIndex;

        for (;;) {
            lChild = (i << 1) + 1;
            rChild = lChild + 1;
            maxIndex = i;

            if (lChild < k && maxHeap[maxIndex] < maxHeap[lChild]) {
                maxIndex = lChild;
            }
            if (rChild < k && maxHeap[maxIndex] < maxHeap[rChild]) {
                maxIndex = rChild;
            }

            if (maxIndex != i) {
                swap(maxHeap[i], maxHeap[maxIndex]);
                heapify(maxHeap, k, maxIndex);
            } else {
                break;
            }
        }
    }
    
    void createHeap(vector<int> &maxHeap, int k) {
        for (int i = (k >> 1) - 1; i >= 0; i--) {
            heapify(maxHeap, k, i);
        }
    }
};

int main()
{
    int arr[] = {4,5,1,6,2,7,3,8};
    vector<int> test(arr, arr + 8);
    Solution solution = Solution();
    vector<int> ans = solution.GetLeastNumbers_Solution(test, 4);
    cout << ans[0] << ans[1] << ans[2] << ans[3] << endl;
    return 0;
}
