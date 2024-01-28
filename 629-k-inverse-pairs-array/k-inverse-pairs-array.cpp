class Solution {
public:
    const int M = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int N = 1; N <= n; N++) {
            for (int K = 1; K <= k; K++) {
                dp[N][K] = (dp[N][K - 1] + dp[N - 1][K]) % M;
                if (K - N >= 0) {
                    dp[N][K] = (dp[N][K] -dp[N-1][K-N] + M)%M;
                }
            }
        }
        return dp[n][k];
    }
};