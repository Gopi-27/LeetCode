class MedianFinder {
public:
    multiset<int>l,r;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(l.empty() && r.empty())l.insert(num);
        else {
            if(*l.rbegin() >= num)l.insert(num);
            else r.insert(num);
            if(abs((int)(l.size() - r.size())) > 1){
                if(l.size() > r.size()){
                    r.insert(*l.rbegin());
                    l.erase(--l.end());
                }else{
                    l.insert(*r.begin());
                    r.erase(r.begin());
                }
            }
        }
    }
    
    double findMedian() {
        if(l.size() == r.size())return (double)((*l.rbegin() + *r.begin()))/2.0;
        if(l.size() > r.size())return *l.rbegin();
        return *r.begin();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */