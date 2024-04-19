class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= 2; j++){
                dp[i] = dp[i] + dp[i-j];
            }
        }
        return dp[n];
    }
};
