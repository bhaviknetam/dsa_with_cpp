class Solution {
private:
    unordered_map<string, bool> m;
    string key(int i, int j){
        return to_string(i) + "," + to_string(j);
    }

public:
    bool func(int i, int j, string curr, string& s, string& p) {
        if (i == p.size() && j == s.size()) {
            if (curr == s)
                return true;
            return false;
        }
        if (curr.size() > s.size())
            return false;
        string k = key(i, j);
        if (m.count(k))
            return m[k];
        bool ans = false;
        string temp = curr;
        if (i + 1 < p.size() && p[i + 1] == '*') {
            ans |= func(i + 2, j, temp, s, p);
            if (p[i] != '.' && p[i] != s[j])
                return m[k] = ans;
            temp.push_back(s[j]);
            ans |= func(i, j + 1, temp, s, p);
        } else {
            if (p[i] != '.' && p[i] != s[j])
                return m[k] = ans;
            temp.push_back(s[j]);
            ans |= func(i + 1, j + 1, temp, s, p);
        }
        return m[k] = ans;
    }

    bool isMatch(string s, string p) { return func(0, 0, "", s, p); }
};