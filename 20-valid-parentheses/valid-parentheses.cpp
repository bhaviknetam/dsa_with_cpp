class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for (char c : str) {
            if (!s.empty() and ((c == ')' and s.top() == '(') or
                                (c == '}' and s.top() == '{') or
                                (c == ']' and s.top() == '['))) {
                s.pop();
                continue;
            }
            s.push(c);
        }
        return s.size() == 0;
    }
};