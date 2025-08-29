class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<int> dirs = {1, 0, -1, 0, 1};
        int c = image[sr][sc];
        function<void(int, int)> dfs = [&](int sr, int sc){
            for(int i = 0; i < 4; i++){
                int nextsr = sr + dirs[i];
                int nextsc = sc + dirs[i+1];
                if(nextsr<0 || nextsc<0 || nextsc>=m || nextsr>=n || vis[nextsr][nextsc] || image[nextsr][nextsc] != c || image[nextsr][nextsc] == color)continue;
                vis[nextsr][nextsc] = true;
                dfs(nextsr, nextsc);
            }
            image[sr][sc] = color;
        };
        dfs(sr, sc);
        return image;
    }
};