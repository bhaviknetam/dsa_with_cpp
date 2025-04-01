class Solution {
private:
    unordered_map<string, bool> m;
    string key(int i, int j){
        return to_string(i) + "," + to_string(j);
    }

public:
    bool func(int i, int j, string& s, string& p) {
        if (i == p.size() && j == s.size()) {
            return true;
        }
        if (i == p.size())
            return false;
        string k = key(i, j);
        if (m.count(k))
            return m[k];
        bool match = (j < s.size() && (p[i] == s[j] || p[i] == '.'));
        bool ans = false;
        if (i + 1 < p.size() && p[i + 1] == '*') {
            ans = func(i + 2, j, s, p) || (match && func(i, j + 1, s, p));
        } else {
            ans = (match && func(i + 1, j + 1, s, p));
        }
        return m[k] = ans;
    }

    bool isMatch(string s, string p) { return func(0, 0, s, p); }
};