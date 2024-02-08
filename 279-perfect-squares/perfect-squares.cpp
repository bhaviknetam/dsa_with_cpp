class Solution {
public:
    int dp[100000];
    int numSquares(int n) {
        if(n < 0) return 1e9;
        if(n == 0) return 0;
        if(dp[n] != 0) return dp[n];
        int count = INT_MAX;
        for(int i = 1; i <= n; i++){
            count = min(count, numSquares(n - (i*i)) + 1);
        }
        return dp[n] = count;
    }
};