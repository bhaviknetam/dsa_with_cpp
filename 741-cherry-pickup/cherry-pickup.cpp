class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(2 * n, 
                            vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][0] = grid[0][0];
        for(int k = 1; k < 2 * n - 1; k++){
            for(int r1 = 0; r1 < n; r1++){
                int c1 = k - r1;
                if(c1 < 0 || c1 >= n || grid[r1][c1] == -1) continue;
                for(int r2 = 0; r2 < n; r2++){
                    int c2 = k - r2;
                    if(c2 < 0 || c2 >= n ||  grid[r2][c2] == -1) continue;
                    int ans = dp[k-1][r1][r2];
                    if(r1 > 0) ans = max(ans, dp[k-1][r1-1][r2]);
                    if(r2 > 0) ans = max(ans, dp[k-1][r1][r2-1]);
                    if(r1 > 0 && r2 > 0) ans = max(ans, dp[k-1][r1-1][r2-1]);
                    if(ans == -1) continue;
                    dp[k][r1][r2]=ans+grid[r1][c1]+(r1!=r2?grid[r2][c2]:0);
                }
            }
        }
        return max(0,dp[2*n - 2][n-1][n-1]);
    }
};