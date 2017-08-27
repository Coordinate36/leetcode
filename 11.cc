/*class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int max_area = (j - i) * min(height[i], height[j]);
        while (i != j) {
            if (height[i] <= height[j]) {
                while (i != j && height[i + 1] <= height[i]) {
                    ++i;
                } 
                if (i != j) {
                    ++i;
                }
            } else {
                while (i != j && height[j - 1] <= height[j]) {
                    --j;
                }
                if (i != j) {
                    --j;
                }
            }
            max_area = max(max_area, (j - i) * min(height[i], height[j]));
        }
        return max_area;
    }
};*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max_area = (r - l) * min(height[l], height[r]);
        while (l != r) {
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
            max_area = max(max_area, (r - l) * min(height[l], height[r]));
        }
        return max_area;
    }
};

