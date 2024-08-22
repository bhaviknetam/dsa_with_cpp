class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& board,
             vector<vector<bool>>& vis) {
        if (i < 0 || j < 0 || j >= m || i >= n)
            return;
        if (board[i][j] == 'X')
            return;
        if (vis[i][j])
            return;
        vis[i][j] = true;
        board[i][j] = 'M';
        dfs(i + 1, j, n, m, board, vis);
        dfs(i - 1, j, n, m, board, vis);
        dfs(i, j + 1, n, m, board, vis);
        dfs(i, j - 1, n, m, board, vis);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] and board[0][j] == 'O')
                dfs(0, j, n, m, board, vis);
            if (!vis[n - 1][j] and board[n - 1][j] == 'O')
                dfs(n - 1, j, n, m, board, vis);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] and board[i][0] == 'O')
                dfs(i, 0, n, m, board, vis);
            if (!vis[i][m - 1] and board[i][m - 1] == 'O')
                dfs(i, m - 1, n, m, board, vis);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'M')
                    board[i][j] = 'O';
            }
        }
    }
};