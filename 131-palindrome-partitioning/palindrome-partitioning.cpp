class Solution {
private: vector<vector<string>> ans;
public:
    void helper(int i, vector<string>& p, string s, vector<vector<bool>>& dp){
        int n = s.size();
        if(i == n){
            ans.push_back(p);
            return;
        }
        for(int j = i; j < n; j++){
            if(dp[i][j]){
                p.push_back(s.substr(i, j - i + 1));
                helper(j + 1, p, s, dp);
                p.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> p;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
        helper(0, p, s, dp);
        return ans;
    }
};