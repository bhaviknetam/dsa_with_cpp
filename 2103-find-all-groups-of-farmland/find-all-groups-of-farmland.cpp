class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j, int& maxx, int& maxy,
             int& n, int& m) {
        if (i < 0 || j < 0 || j > m - 1 || i > n - 1 || land[i][j] == 0)
            return;
        land[i][j] = 0;
        maxx = max(maxx, i);
        maxy = max(maxy, j);
        dfs(land, i + 1, j, maxx, maxy, n, m);
        //dfs(land, i - 1, j, maxx, maxy, n, m);
        dfs(land, i, j + 1, maxx, maxy, n, m);
        //dfs(land, i, j - 1, maxx, maxy, n, m);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (land[i][j] == 1) {
                    int maxx = i, maxy = j;
                    dfs(land, i, j, maxx, maxy, n, m);
                    ans.push_back({i, j, maxx, maxy});
                }
            }
        }
        return ans;
    }
};