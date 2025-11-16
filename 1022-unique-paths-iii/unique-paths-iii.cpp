class Solution {
private:
    int ans, totEmpty;
    vector<int> dirs = {1, 0, -1, 0, 1};
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int ct){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == -1) return;
        if(grid[i][j] == 2){
            if(ct == totEmpty) ans++;
            return;
        }
        int temp = grid[i][j];
        grid[i][j] = -1;
        for(int d = 0; d < 4; d++){
            dfs(i + dirs[d], j + dirs[d+1], grid, ct+1);
        }
        grid[i][j] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int x = -1, y = -1;
        ans = totEmpty = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) x = i, y = j;
                if(grid[i][j] >= 0) totEmpty++;
            }
        }
        dfs(x, y, grid, 1);
        return ans;
    }
};