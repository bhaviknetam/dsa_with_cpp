class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> v(numRows);
        int curr = 0, d;
        for(int i = 0; i < s.size(); i++){
            if(curr == 0) d = 1;
            else if(curr == numRows - 1) d = -1;
            v[curr].push_back(s[i]);
            curr += d;
        }
        string ans;
        for(auto& str : v) ans += str;
        return ans;
    }
};