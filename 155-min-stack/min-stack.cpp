class MinStack {
private:
    vector<int> minVal;
    stack<int> s;
public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if(minVal.empty() || minVal.back() >= val){
            minVal.push_back(val);
        }
    }
    
    void pop() {
        if(minVal.back() == s.top()) minVal.pop_back();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minVal.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */