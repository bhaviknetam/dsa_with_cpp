class Solution {
private:
    string temp;

public:
    vector<int> manacher_odd(string s) {
        temp = s;
        int n = s.size();
        s = "$" + s + "^";
        vector<int> p(n + 2);
        int l = 1, r = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + (r - i)]));
            // cout << p[i]
            while (s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
        return vector<int>(begin(p) + 1, end(p) - 1);
    }

    vector<int> manacher(string s) {
        string t;
        for (auto c : s) {
            t += string("#") + c;
        }
        auto res = manacher_odd(t + "#");
        // cout << res.size() << '\n';
        return vector<int>(begin(res), end(res));
    }
    string shortestPalindrome(string s) {
        if(s.size() <= 1) return s;
        auto ans = manacher(s);
        int longest_length = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (i - ans[i] + 1 == 0) {
                longest_length = 2*ans[i] - 1;
            }
        }
        string t = temp.substr(0, longest_length);
        t.erase(remove(t.begin(), t.end(), '#'), t.end());
        string a = s.substr(t.size(), s.size() - t.size());
        reverse(a.begin(), a.end());
        return a + s;
    }
};