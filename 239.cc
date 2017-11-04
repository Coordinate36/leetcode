/*class Solution {
public:
    int getMax(map<int, int> Map) {
        auto iter = Map.end();
        --iter;
        return iter->first;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> res;
        if (k == 0) {
            return res;
        }
        map<int, int> Map;
        for (int i = 0; i < k; ++i) {
            Map[nums[i]]++;
        }
        res.push_back(getMax(Map));
        for (int i = k; i < size; ++i) {
            Map[nums[i - k]]--;
            if (Map[nums[i - k]] == 0) {
                Map.erase(nums[i - k]);
            }
            Map[nums[i]]++;
            res.push_back(getMax(Map));
        }
        return res;
    }
};*/

/*class Solution {
public:
    int getMax(vector<int> &nums, int begin, int end, int lastMax) {
        if (nums[end] >= lastMax) {
            return nums[end];
        }
        if (nums[begin] != lastMax) {
            return lastMax;
        }

        int res = nums[begin + 1];

        for (int i = begin + 2; i <= end; ++i) {
            res = max(res, nums[i]);
        }

        return res;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> res;

        if (k == 0) {
            return res;
        }

        int Max = nums[0];
        for (int i = 1; i < k; ++i) {
            Max = max(nums[i], Max);
        }

        res.push_back(Max);
        for (int i = 0; i < size - k; ++i) {
            Max = getMax(nums, i, i + k, Max);
            res.push_back(Max);
        }
        
        return res;
    }
};*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dequeue;
        for (int i = k - 1; i > 0; --i) {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
                if (dequeue.empty()) {
                    dequeue.push_back(nums[i]);
                } else {
                    if (dequeue.back() < nums[i]) {
                        dequeue.push_back(nums[i]);
                    }
                }
            }
        } 
        
    }
};