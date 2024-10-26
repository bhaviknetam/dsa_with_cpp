class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int INF = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = piles[i];
        }
        int sum = accumulate(piles.begin(), piles.end(), 0);
        for(int i = n - 1; i >=0; i--){
            for(int j = i+1; j < n; j++){
                dp[i][j] = 
            max(piles[i] + min(dp[i+1][j-1],(i+2<n)?dp[i+2][j]:INF),
                piles[j] + min(dp[i+1][j-1],(j-2>=0)?dp[i][j-2]:INF));
            }
        }
        return dp[0][n-1] > sum - dp[0][n-1];
    }
};