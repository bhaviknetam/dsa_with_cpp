class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        pq.push({grid[0][0], {0, 0}});
        vector<int> dirs = {0, 1, 0, -1, 0};
        while(!pq.empty()){
            auto [t, loc] = pq.top();
            auto [i, j] = loc;
            pq.pop();
            if(i == n-1 && j == n-1) return t;
            if(vis[i][j]) continue;
            vis[i][j] = true;
            for(int d = 0; d < 4; d++){
                int ni = i + dirs[d];
                int nj = j + dirs[d+1];
                if(ni<0||ni>=n||nj<0||nj>=n||vis[ni][nj])continue;
                pq.push({max(t, grid[ni][nj]), {ni, nj}});
            }
        }
        return -1;
    }
};