class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deq;
        for (int i = 0; i < nums.size(); ++i) {
            while (deq.size() && nums[i] > deq.front()) {
                deq.pop_front();
            }
            deq.push_front(nums[i]);
            if (i >= k && nums[i-k] == deq.back()) {
                deq.pop_back();
            }
            if (i >= k - 1) {
                res.push_back(deq.back());
            }
        }
        return res;
    }
};