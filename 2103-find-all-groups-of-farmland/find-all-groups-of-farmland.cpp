class Solution {
public:
    void dfs(vector<vector<int>>& land,vector<vector<bool>>& vis, int i,int j,int& maxx, int& maxy, int& n, int& m){
        if(i < 0 || j < 0 || j > m-1 || i > n-1) return;
        if(vis[i][j]) return;
        vis[i][j]=true;
        if(land[i][j] == 0) return;
        maxx = max(maxx, i);
        maxy = max(maxy, j);
        dfs(land, vis, i + 1, j, maxx,maxy, n, m);
        dfs(land, vis, i - 1, j, maxx,maxy,n,m);
        dfs(land, vis, i, j+1, maxx,maxy,n,m);
        dfs(land, vis, i, j-1, maxx,maxy,n,m);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && land[i][j] == 1) {
                    int maxx = 0, maxy = 0;
                    dfs(land, vis, i, j, maxx, maxy, n, m);
                    ans.push_back({i, j, maxx, maxy});
                }
            }
        }
        return ans;
    }
};