class FrontMiddleBackQueue {
public:
    deque<int>dq;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        dq.push_front(val);
    }
    
    void pushMiddle(int val) {
        int n = dq.size();
        int idx = n / 2;
        dq.push_back(val);
        for(int i = n - 1; i >= idx; i--)dq[i + 1] = dq[i];
        dq[idx] = val;
    }
    
    void pushBack(int val) {
        dq.push_back(val);
    }
    
    int popFront() {
        if(dq.empty())return -1;
        int val = dq.front();
        dq.pop_front();
        return val;
    }
    
    int popMiddle() {
        if(dq.empty())return -1;
        int n = dq.size();
        int idx = (n - 1)/2;
        int val = dq[idx];
        for(int i = idx; i < n - 1; i++){
            dq[i] = dq[i + 1];
        }
        dq.pop_back();
        return val;
    }
    
    int popBack() {
        if(dq.empty())return -1;
        int val = dq.back();
        dq.pop_back();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */