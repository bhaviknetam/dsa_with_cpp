class Solution {
public:
    string removeDuplicates(string str) {
        stack<char> s;
        for(char& c : str){
            if(!s.empty() && s.top() == c) s.pop();
            else s.push(c);
        }
        string ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};