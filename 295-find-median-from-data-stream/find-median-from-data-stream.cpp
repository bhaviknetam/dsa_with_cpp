class MedianFinder {
private: 
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if(hi.size() > lo.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        if((lo.size() + hi.size()) & 1) return (double)lo.top();
        return (lo.top() + hi.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */