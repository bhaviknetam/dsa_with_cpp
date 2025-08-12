class Solution {
private:
    vector<vector<string>> ans;
    vector<bool> c, d, ad;
public:
    void helper(int row, int n, vector<string>& s){
        if(row == n){
            ans.push_back(s);
            return;
        }
        for(int col = 0; col < n; col++){
            if(!c[col] && !d[row + n - col] && !ad[row + col]){
                c[col] = d[row + n - col] = ad[row + col] = true;
                s[row][col] = 'Q';
                helper(row + 1, n, s);
                s[row][col] = '.';
                c[col] = d[row + n - col] = ad[row + col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        c.resize(n, false);
        d.resize(2 * n, false);
        ad.resize(2 * n, false);
        string k;
        for(int i = 0; i < n; i++) k.push_back('.');
        vector<string> s;
        for(int i = 0; i < n; i++) s.push_back(k);
        helper(0, n, s);
        return ans;
    }
};