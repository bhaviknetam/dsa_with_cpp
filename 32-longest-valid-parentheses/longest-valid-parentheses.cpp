class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int i = 0;
        while(i < s.size()){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(!st.empty() && s[st.top()] == '(') st.pop();
                else st.push(i);
            }
            i++;
        }
        int b = s.size(), ans = 0;
        while(!st.empty()){
            // cout << st.top()<<';';
            ans = max(ans, b - st.top() - 1);
            b = st.top();
            st.pop();
        }
        ans = max(ans, b);
        return ans;
    }
};