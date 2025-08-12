class Solution {
private:
    vector<vector<char>> ans;
    vector<vector<bool>> visRow, visCol, visBox;
public:
    int getBox(int r, int c){
        int block = 0;
        block += r / 3 * 3;
        block += (c >= 3) + (c >= 6);
        return block;
    }

    void helper(int row, int col, vector<vector<char>>& board) {
        if (row == 9) {
            ans = board;
            return;
        }
        if (board[row][col] != '.') {
            if (col + 1 == 9) {
                helper(row + 1, 0, board);
            } else {
                helper(row, col + 1, board);
            }
        } else {
            int box = getBox(row, col);
            for (int i = 1; i <= 9; i++) {
                if (!visRow[row][i] && !visCol[col][i] && !visBox[box][i]) {
                    visRow[row][i] = visCol[col][i] = visBox[box][i] = 1;
                    board[row][col] = i + '0';
                    if (col + 1 == 9) {
                        helper(row + 1, 0, board);
                    } else {
                        helper(row, col + 1, board);
                    }
                    visRow[row][i] = visCol[col][i] = visBox[box][i] = 0;
                    board[row][col] = '.';
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        visRow.assign(9, vector<bool>(10, false));
        visCol.assign(9, vector<bool>(10, false));
        visBox.assign(9, vector<bool>(10, false));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                visRow[i][board[i][j] - '0'] = true;
                visCol[j][board[i][j] - '0'] = true;
                visBox[getBox(i,j)][board[i][j]-'0']=true;
            }
        }
        helper(0, 0, board);
        board = ans;
        ans.clear();
        visRow.clear();
        visCol.clear();
        visBox.clear();
    }
};