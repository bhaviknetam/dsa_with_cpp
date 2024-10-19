class Solution {
private:
    vector<pair<int, int>> points = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> vis;

public:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = true;
        for (auto& point : points) {
            int p1 = i + point.first, p2 = j + point.second;
            if (p1 >= 0 and p2 >= 0 and p1 < n and p2 < m and
                grid[p1][p2] == '1' and !vis[p1][p2]) {
                dfs(p1, p2, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis.resize(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] and grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};