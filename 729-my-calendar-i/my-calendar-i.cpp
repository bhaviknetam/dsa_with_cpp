class MyCalendar {
private:
    map<int, int> m;
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        auto next = m.lower_bound(endTime);
        if(next == m.begin()){
            m.insert({startTime, endTime});
            return true;
        }
        --next;
        if(next->second <= startTime){
            m.insert({startTime, endTime});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */