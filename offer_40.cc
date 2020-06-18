// class Solution {
// public:
//     vector<int> getLeastNumbers(vector<int>& arr, int k) {
//         int left = 0;
//         int right = arr.size() - 1;
//         vector<int> ans;
//         int n = k;
//         while (right >= left) {
//             selectPivot(arr, left, right);
//             int pos = partition(arr, left, right);
//             int num = pos - left + 1;
//             if (num == k) {
//                 break;
//             } else if (num > k) {
//                 right = pos - 1;
//             } else {
//                 k -= num;
//                 left = pos + 1;
//             }
//         }
//         for (int i = 0; i < n; ++i) {
//             ans.push_back(arr[i]);
//         }
//         return ans;
//     }

//     int partition(vector<int>& arr, int left, int right) {
//         int pivot = arr[right];
//         int i = left - 1;
//         for (int j = left; j < right; ++j) {
//             if (arr[j] <= pivot) {
//                 swap(arr[++i], arr[j]);
//             }
//         }
//         swap(arr[++i], arr[right]);
//         return i;
//     }

//     void selectPivot(vector<int>& arr, int left, int right) {
//         int mid = (left + right) >> 1;
//         if (arr[right] > arr[left] && arr[right] > arr[mid]) {
//             if (arr[left] < arr[mid]) {
//                 swap(arr[right], arr[mid]);
//             } else {
//                 swap(arr[right], arr[left]);
//             }
//         } else if (arr[right] < arr[left] && arr[right] < arr[mid]) {
//             if (arr[left] > arr[mid]) {
//                 swap(arr[right], arr[mid]);
//             } else {
//                 swap(arr[right], arr[left]);
//             }
//         }
//     }
// };

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        for (int i = arr.size() / 2 - 1; i >= 0; --i) {
            minHeapify(arr, arr.size() - 1, i);
        }
        for (int i = 0; i < k; ++i) {
            int bottom = arr.size() - 1 - i;
            swap(arr[i], arr[bottom]);
            ans.push_back(arr[bottom]);
            minHeapify(arr, bottom - 1, 0);
        }
        return ans;
    }

    void minHeapify(vector<int>& arr, int end, int parent) {
        int child = (parent << 1) + 1;
        while (child <= end) {
            if (child + 1 <= end && arr[child+1] < arr[child]) {
                ++child;
            }
            if (arr[parent] < arr[child]) {
                break;
            }
            swap(arr[parent], arr[child]);
            parent = child;
        }
    }
}