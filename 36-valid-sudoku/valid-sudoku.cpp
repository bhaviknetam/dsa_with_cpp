class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<bool> visR(10, false), visC(10, false);
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(visR[board[i][j]]) return false;
                visR[board[i][j]] = true;
            }
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                if(visC[board[j][i]]) return false;
                visC[board[j][i]] = true;
            }
        }
        for(int i = 0; i < 9; i+=3 ){
            for(int j = 0; j < 9; j+=3){
                vector<bool> visB(10, false);
                for(int x = i; x < i + 3; x++){
                    for(int y = j; y < j + 3; y++){
                        if(board[x][y]=='.') continue;
                        if(visB[board[x][y]]) return false;
                        visB[board[x][y]] = true;
                    }
                }
            }
        }
        return true;
    }
};