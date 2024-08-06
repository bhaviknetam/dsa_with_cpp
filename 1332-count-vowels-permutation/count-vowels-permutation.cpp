class Solution {
public:
    int countVowelPermutation(int n) {
        long long mod = 1e9 + 7;
        vector<vector<long long>> dp(n+1, vector<long long>(6, 0));
        for(int i=1;i<=5;i++){
            dp[1][i] = 1;
        }
        for(int i=2;i<=n;i++){
            dp[i][1] = dp[i-1][2] % mod;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % mod;
            dp[i][3] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4] + dp[i-1][5])%mod;
            dp[i][4] = (dp[i-1][3] + dp[i-1][5])%mod;
            dp[i][5] = (dp[i-1][1])%mod;
        }
        long long ans = 0;
        for(int i = 1; i <= 5; i++){
            ans = (ans + dp[n][i])%mod;
        }
        return ans;
    }
};