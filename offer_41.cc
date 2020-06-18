class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (minHeap.size() == maxHeap.size()) {
            maxHeap.emplace(num);
            minHeap.emplace(maxHeap.top());
            maxHeap.pop();
        } else {
            minHeap.emplace(num);
            maxHeap.emplace(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return double(minHeap.top() + maxHeap.top()) / 2;
        }
        return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */