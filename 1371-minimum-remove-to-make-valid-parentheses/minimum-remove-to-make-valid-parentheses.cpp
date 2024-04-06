class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        unordered_set<int> store;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == ')' and st.empty())
                continue;
            if (s[i] == '(') {
                st.push(i);
                continue;
            }
            if (s[i] == ')' and !st.empty()) {
                int temp = st.top();
                store.insert(i);
                store.insert(temp);
                st.pop();
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' and !store.count(i)) {
                continue;
            }
            if (s[i] == ')' and !store.count(i)) {
                continue;
            } else
                ans.push_back(s[i]);
        }
        return ans;
    }
};