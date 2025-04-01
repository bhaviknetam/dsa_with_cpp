class Solution {
private: vector<string> ans;
public:
    void func(string &s, int open, int close, int n){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            s.push_back('(');
            func(s, open + 1, close, n);
            s.pop_back();
        }
        if(open > close){
            s.push_back(')');
            func(s, open, close + 1, n);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s;
        func(s, 0, 0, n);
        return ans;
    }
};