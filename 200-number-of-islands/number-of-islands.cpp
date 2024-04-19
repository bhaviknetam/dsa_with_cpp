class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i,
             int j, int n, int m) {
        if (i < 0 || i > n - 1 || j > m - 1 || j < 0) {
            return;
        }
        if (vis[i][j])
            return;
        vis[i][j] = true;
        if(grid[i][j] == '0') return;
        dfs(grid, vis, i + 1, j, n, m);
        dfs(grid, vis, i - 1, j, n, m);
        dfs(grid, vis, i, j + 1, n, m);
        dfs(grid, vis, i, j - 1, n, m);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j]=='1') {
                    ans++;
                    dfs(grid, vis, i, j, n, m);
                }
            }
        }
        return ans;
    }
};