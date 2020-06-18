class MaxQueue {
public:
    deque<int> deq;
    queue<int> q;
    MaxQueue() {

    }
    
    int max_value() {
        return deq.empty() ? -1 : deq.back();
    }
    
    void push_back(int value) {
        q.push(value);
        while (deq.size() && value > deq.front()) {
            deq.pop_front();
        }
        deq.push_front(value);
    }
    
    int pop_front() {
        if (deq.empty()) {
            return -1;
        }
        int value = q.front();
        q.pop();
        if (deq.back() == value) {
            deq.pop_back();
        }
        return value;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */