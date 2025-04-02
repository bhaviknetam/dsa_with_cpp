class Solution {
private:
    vector<vector<int>> dp;
public:
    bool func(int i, int j, string& s, string& p){
        if(i == p.size() && j==s.size()){
            return true;
        }
        if(i == p.size() || j > s.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        if(p[i] == '?'){
            ans = func(i+1, j+1, s, p);
        }else if(p[i] == '*'){
            ans = func(i, j+1, s, p) || func(i+1, j, s, p);
        }else{
            if(p[i] != s[j]) return dp[i][j] = false;
            ans = func(i+1, j+1, s, p);
        }
        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        dp.resize(p.size() + 1, vector<int>(s.size() + 1, -1));
        return func(0, 0, s, p);
    }
};