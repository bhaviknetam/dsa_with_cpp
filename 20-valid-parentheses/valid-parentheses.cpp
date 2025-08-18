class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(char& c : str){
            if(!s.empty() && ((c == ')' && s.top() == '(') ||
                (c == ']' && s.top() == '[') ||
                (c == '}' && s.top() == '{')))
                s.pop();
            else
                s.push(c);
        }
        return s.size() == 0;
    }
};