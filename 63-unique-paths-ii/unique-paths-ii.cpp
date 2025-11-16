class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[n-1][m-1]) return 0;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        ans[0][0] = 1;
        for(int i = 1; i < n; i++){
            if(obstacleGrid[i][0]) break;
            ans[i][0] = 1;
        }
        for(int j = 1; j < m; j++){
            if(obstacleGrid[0][j]) break;
            ans[0][j] = 1;
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(obstacleGrid[i][j]) continue;
                ans[i][j] = ans[i-1][j] + ans[i][j-1];
            }
        }
        return ans[n-1][m-1];
    }
};