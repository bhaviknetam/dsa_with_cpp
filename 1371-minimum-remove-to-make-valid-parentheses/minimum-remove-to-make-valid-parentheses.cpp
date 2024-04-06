class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' and st.empty()) {
                s[i] = '@';
                continue;
            }
            if (s[i] == '(') {
                s[i] = '@';
                st.push(i);
                continue;
            }
            if (s[i] == ')' and !st.empty()) {
                int temp = st.top();
                s[temp] = '(';
                st.pop();
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '@')
                ans.push_back(s[i]);
        }
        return ans;
    }
};