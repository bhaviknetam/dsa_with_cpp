class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int INF = 1e9;
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i = 0; i <n; i++){
            for(int j = 0;j < m; j++){
                if(i == 0 && j==0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                dp[i][j] = grid[i][j]+ min(i>0?dp[i-1][j]:INF, j>0?dp[i][j-1]:INF);
            }
        }
        return dp[n-1][m-1];
    }
};