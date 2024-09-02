class Solution {
private:
    int store[2001][2001];
    int solve(string& s, int i, int j, vector<vector<int>>& dp){
        if(i >= j) return 0;
        if(store[i][j] != -1){
            return store[i][j];
        }
        if(dp[i][j])return store[i][j] = 0;
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            ans = min(ans, 1 + solve(s, i, k, dp) +solve(s, k+1, j, dp));
        }
        return store[i][j] = ans;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i =0 ; i< n;i++){
            dp[i][i] = 1;
        }
        for(int i= n-2; i >= 0 ;i--){
            for(int j = i+1; j < n; j++){
                if(s[i] == s[j]){
                    if(j - i == 1){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
        }
        vector<int> cuts(n, INT_MAX);
        cuts[0] = 0;
        for(int i = 1; i < n; i++){
            if(dp[0][i]){
                cuts[i] = 0;
                continue;
            }
            for(int k = 0; k < i; k++){
                if(dp[k+1][i] and cuts[k] + 1 < cuts[i]){
                    cuts[i] = cuts[k] + 1;
                }
            }
        }
        return cuts[n-1];
    }
};