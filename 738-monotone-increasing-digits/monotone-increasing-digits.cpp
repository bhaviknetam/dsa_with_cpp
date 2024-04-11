class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        stack<char> s;
        int sz = num.size();
        for(int i=0;i<sz;i++){
            if(!s.empty() && s.top() > num[i]){
                char c = num[i];
                while(!s.empty() && s.top() > c){
                    char b = s.top();
                    s.pop();
                    c = b - 1;
                }
                s.push(c);
                break;
            }else
                s.push(num[i]);
        }
        string ans ="";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        for(int i = (int)ans.size(); i < sz;i++){
            ans.push_back('9');
        }
        return stoi(ans);
    }
};