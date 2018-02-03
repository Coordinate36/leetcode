#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int begin = 0;
        int end = matrix.size() - 1;
        for (; begin < end; ++begin, --end) {
            rotate(matrix, begin, end);
        }
    }

    void rotate(vector<vector<int>>& matrix, int begin, int end) {
        int tmp;
        for (int i = begin; i < end; ++i) {
            tmp = matrix[i][end];
            matrix[i][end] = matrix[begin][i];
            matrix[begin][i] = matrix[end - i + begin][begin];
            matrix[end - i + begin][begin] = matrix[end][end - i + begin];
            matrix[end][end - i + begin] = tmp;
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution solution;
    solution.rotate(matrix);
    return 0;
}