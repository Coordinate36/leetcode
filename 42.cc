/* class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int first = 0;
        int end = height.size() - 1;
        for (int i = 1; first < end; ++i) {
            while (height[first] < i) {
                ++first;
            }
            while (height[end] < i) {
                --end;
            }
            for (int j = first + 1; j < end; ++j) {
                if (height[j] < i) {
                    // cout << j << " " << i << " " << first << " " << end << endl;
                    ++ans;
                }
            }
        }
        return ans;
    }
}; */

/* class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int first = 0;
        int end = height.size() - 1;
        int last_height = 0;
        set<int> gradient(height.begin(), height.end());
        for (auto iter = gradient.begin(); iter != gradient.end(); ++iter) {
            while (height[first] < *iter) {
                ++first;
            }
            while (height[end] < *iter) {
                --end;
            }
            for (int j = first + 1; j < end; ++j) {
                if (height[j] < *iter) {
                    ans += *iter - max(height[j], last_height);
                }
            }
            last_height = *iter;
        }
        return ans;
    }
}; */

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        
        int max_height = 0;
        vector<int> left(size);
        vector<int> right(size);

        for (int i = 0; i < size; ++i) {
            left[i] = max_height;
            max_height = max(max_height, height[i]);
        }

        max_height = 0;
        for (int i = size - 1; i >= 0; --i) {
            right[i] = max_height;
            max_height = max(max_height, height[i]);
        }

        for (int i = 0; i < size; ++i) {
            int dist = min(left[i], right[i]) - height[i];
            if (dist > 0) {
                ans += dist;
            }
        }

        return ans;
    }
};