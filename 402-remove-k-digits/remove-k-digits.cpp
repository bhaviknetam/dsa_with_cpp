class Solution {
public:
    string removeKdigits(std::string num, int k) {
        if (k >= num.size())
            return "0";

        stack<char> s;

        for (char& digit : num) {
            while (k > 0 && !s.empty() && s.top() > digit) {
                s.pop();
                k--;
            }
            s.push(digit);
        }

        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }

        string ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        while (!ans.empty() && ans.back() == '0') {
            ans.pop_back();
        }

        if (ans.empty())
            return "0";

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
