class Solution {
private:
    bool found(vector<vector<char>>& board, int i, int j, int k, string word,
               vector<vector<bool>>& visited) {
        if (k == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            visited[i][j])
            return false;

        if (board[i][j] != word[k])
            return false;

        visited[i][j] = true;

        bool flag1, flag2, flag3, flag4;
        flag1 = found(board, i, j + 1, k + 1, word, visited);
        flag2 = found(board, i, j - 1, k + 1, word, visited);
        flag3 = found(board, i + 1, j, k + 1, word, visited);
        flag4 = found(board, i - 1, j, k + 1, word, visited);

        visited[i][j] = false;

        return (flag1 || flag2 || flag3 || flag4);
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (found(board, i, j, 0, word, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
