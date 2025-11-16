class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[n-1][m-1] = dungeon[n-1][m-1] >= 0 ? 1 : abs(dungeon[n-1][m-1])+1;
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(i == n-1 && j == m-1) continue;
                int left = (j + 1 < m ? dp[i][j+1] : INT_MAX);
                int down = (i + 1 < n ? dp[i+1][j] : INT_MAX);
                dp[i][j] = max(min(left, down) - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};