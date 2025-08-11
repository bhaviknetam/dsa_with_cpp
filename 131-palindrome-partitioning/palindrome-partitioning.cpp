class Solution {
private: vector<vector<string>> ans;
public:
    void helper(int i, vector<string>& p, string s, vector<vector<bool>>& dp){
        int n = s.size();
        if(i == n){
            int sz = p.back().size();
            if(dp[n - sz][n - 1])
                ans.push_back(p);
            return;
        }
        if(p.empty() || dp[i - p.back().size()][i - 1]){
            p.push_back(string() + s[i]);
            helper(i+1, p, s, dp);
            p.pop_back();
        }
        if(i != 0){
            p.back().push_back(s[i]);
            helper(i+1, p, s, dp);
            p.back().pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> p;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(j == i){
                    dp[i][j] = true;
                }else if(j - i == 1){
                    dp[i][j] = (s[i] == s[j]);
                }else{
                    dp[i][j] = (s[i] == s[j]) & dp[i+1][j-1];
                }
            }
        }
        helper(0, p, s, dp);
        return ans;
    }
};