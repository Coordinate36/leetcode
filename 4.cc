// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int size1 = nums1.size();
//         int size2 = nums2.size();
//         int half = (size1 + size2 - 1) / 2;
//         int i = 0, j = 0;
//         while ((i != size1) && (j != size2)) {
//             if (i + j == half) {
//                 if ((size1 + size2) & 1) {
//                     return nums1[i] < nums2[j] ? nums1[i]: nums2[j];
//                 }
//                 if (nums1[i] < nums2[j]) {
//                     if (i + 1 != size1) {
//                         return nums1[i + 1] < nums2[j] ? ((double)nums1[i] + nums1[i + 1]) / 2: ((double)nums1[i] + nums2[j]) / 2;
//                     } else {
//                         return ((double)nums1[i] + nums2[j]) / 2;
//                     }
//                 } else {
//                     if (j + 1 != size2) {
//                         return nums2[j + 1] < nums1[i] ? ((double)nums2[j] + nums2[j + 1]) / 2: ((double)nums1[i] + nums2[j]) / 2;
//                     } else {
//                         return ((double)nums1[i] + nums2[j]) / 2;
//                     }
//                 }
//             }
//             if (nums1[i] < nums2[j]) {
//                 ++i;
//             } else {
//                 ++j;
//             }
//         }
//         while (i != size1) {
//             if (i + j == half) {
//                 if ((size1 + size2) & 1) {
//                     return nums1[i];
//                 }
//                 return ((double)nums1[i] + nums1[i + 1]) / 2;
//             }
//             ++i;
//         }
//         while (j != size2) {
//             if (i + j == half) {
//                 if ((size1 + size2) & 1) {
//                     return nums2[j];
//                 }
//                 return ((double)nums2[j] + nums2[j + 1]) / 2;
//             }
//             ++j;
//         }
//     }
// };


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int half = (size1 + size2 - 1) / 2;
        int i = 0, j = 0;
        while ((i != size1) && (j != size2) && (i + j != half)) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        while ((i != size1) && (i + j != half)) {
            ++i;
        }
        while ((j != size2) && (i + j != half)) {
            ++j;
        }
        // cout << i << ", " << j << endl;
        if ((size1 + size2) & 1) {
            if (i == size1 || (j != size2 && nums1[i] > nums2[j])) {
                return nums2[j];
            } else {
                return nums1[i];
            }
        }
        if (i == size1) {
            return ((double)nums2[j] + nums2[j + 1]) / 2;
        }
        if (j == size2) {
            return ((double)nums1[i] + nums1[i + 1]) / 2;
        }
        if (nums1[i] < nums2[j]) {
            if (i + 1 != size1) {
                return nums1[i + 1] < nums2[j] ? ((double)nums1[i] + nums1[i + 1]) / 2: ((double)nums1[i] + nums2[j]) / 2;
            } else {
                return ((double)nums1[i] + nums2[j]) / 2;
            }
        } else {
            if (j + 1 != size2) {
                return nums2[j + 1] < nums1[i] ? ((double)nums2[j] + nums2[j + 1]) / 2: ((double)nums1[i] + nums2[j]) / 2;
            } else {
                return ((double)nums1[i] + nums2[j]) / 2;
            }
        }
    }
};