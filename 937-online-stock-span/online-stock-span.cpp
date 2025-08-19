class StockSpanner {
private:
    stack<pair<int,int>> s;
public:
    StockSpanner() {}
    
    int next(int price) {
        if(s.empty() || price < s.top().first){
            s.push({price, 1});
            return 1;
        }
        int span = 1;
        while(!s.empty() && price >= s.top().first){
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */