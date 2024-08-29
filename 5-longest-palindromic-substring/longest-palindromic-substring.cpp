class Solution {
private:
    string temp;  // To store the transformed string

public:
    vector<int> manacher_odd(string s) {
        temp = s;  // Store the transformed string
        int n = s.size();
        s = "$" + s + "^";
        vector<int> p(n + 2);
        int l = 1, r = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + (r - i)]));
            while (s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
        return vector<int>(begin(p) + 1, end(p) - 1);
    }

    vector<int> manacher(string s) {
        string t;
        for (auto c : s) {
            t += "#" + string(1, c);
        }
        t += "#";  // Append the trailing '#'
        auto res = manacher_odd(t);
        temp = t;  // Store the transformed string for later use
        return res;
    }

    string longestPalindrome(string s) {
        auto ans = manacher(s);
        int longest_length = 0, idx = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] > longest_length) {
                longest_length = ans[i];
                idx = i;
            }
        }

        // Calculate the start and length correctly in the transformed string
        int start = idx - longest_length + 1;
        int length = 2 * longest_length - 1;

        string t = temp.substr(start, length);

        // Remove '#' characters to get the original palindrome
        t.erase(std::remove(t.begin(), t.end(), '#'), t.end());
        return t;
    }
};
