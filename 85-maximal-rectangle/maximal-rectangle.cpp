class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> grid(n, vector<int>(m, 0));
        int ans = 0;
        for(int j = 0; j < m; j++) grid[0][j] = matrix[0][j] - '0';
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0') continue;
                grid[i][j] = grid[i-1][j] + 1;
                ans = max(ans, grid[i][j]);
            }
        }
        for(int i = 0; i < n; i++){
            stack<int> s;
            for(int j = 0; j <= m; j++){
                while(!s.empty() && (j == m||grid[i][s.top()] >= grid[i][j])){
                    int h = grid[i][s.top()];
                    s.pop();
                    int l = (s.empty() ? -1 : s.top());
                    int width = j - l - 1;
                    ans = max(ans, h * width);
                }
                s.push(j);
            }
        }
        return ans;
    }
};