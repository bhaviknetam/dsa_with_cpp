class Solution {
public:
    int countSubstrings(string s) {
        int n =s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        int ans = n;
        for(int i = n-1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(j - i == 1){
                    if(s[i] == s[j])
                        dp[i][j] = 1;
                }else{
                    if(s[i]==s[j]){
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};