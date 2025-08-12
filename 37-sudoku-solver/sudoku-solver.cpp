class Solution {
private:
    vector<vector<bool>> visRow, visCol, visBox;
public:
    int getBox(int r, int c){
        int block = 0;
        block += r / 3 * 3;
        block += (c >= 3) + (c >= 6);
        return block;
    }

    bool helper(int row, vector<vector<char>>& board) {
        for(int i = row; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') continue;
                int box = getBox(i, j);
                for(int k = 1; k <= 9; k++){
                    if(!visRow[i][k] && !visCol[j][k]&& !visBox[box][k]){
                        visRow[i][k]=visCol[j][k]=visBox[box][k]=1;
                        board[i][j] = k + '0';
                        if(helper(i, board)) return true;
                        board[i][j] = '.';
                        visRow[i][k]=visCol[j][k]=visBox[box][k]=0;
                    }
                }
                return false;
            }
        }
        return true;
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
        helper(0, board);
        visRow.clear();
        visCol.clear();
        visBox.clear();
    }
};