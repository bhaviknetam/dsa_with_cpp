class Solution {
public:
    int clumsy(int n) {
        stack<int> s;
        int j = 0, val, t;
        for(int i = n;i>=1;i--){
            switch(j){
                case 0:
                    s.push(s.empty()?i:-i);
                    break;
                case 1:
                    val = s.top() * i;
                    s.pop();
                    s.push(val);
                    break;
                case 2:
                    val = s.top() / i;
                    s.pop();
                    s.push(val);
                    break;
                case 3:
                    val = s.top() + i;
                    s.pop();
                    s.push(val);
                    break;
            }
            j=(j+1)%4;
        }
        int ans = 0;
        while(s.size() > 1){
            ans += s.top();
            // cout<<s.top()<<' ';
            s.pop();
        }
        // cout<<s.top()<< ' ';
        return s.top() + ans;
    }
};