class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> ans;
        stack<pair<int, int>> stk;

        auto isValid = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < n && j < m && !vis[i][j] && land[i][j] == 1;
        };

        auto dfs = [&](int i, int j) {
            int maxx = i, maxy = j;
            stk.push({i, j});
            vis[i][j] = true;

            while (!stk.empty()) {
                auto [x, y] = stk.top();
                stk.pop();
                maxx = max(maxx, x);
                maxy = max(maxy, y);

                vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (isValid(nx, ny)) {
                        stk.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }

            ans.push_back({i, j, maxx, maxy});
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isValid(i, j)) {
                    dfs(i, j);
                }
            }
        }

        return ans;
    }
};