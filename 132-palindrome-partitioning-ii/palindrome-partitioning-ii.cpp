class Solution {
public:
    vector<int> cutdp;
    int helper(int start, string& s, vector<vector<bool>>& dp){
        int n = s.size();
        if(start == n) return -1;
        if(cutdp[start] != -1) return cutdp[start];
        int ans = INT_MAX, res;
        for(int i = start; i < n; i++){
            if(dp[start][i]){
                res = 1 + helper(i + 1, s, dp);
                if(res < ans) ans = res;
            }
        }
        return cutdp[start] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i <n;i++) dp[i][i] = true;
        for(int i = n-2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(j - i == 1){
                    dp[i][j] = (s[i] == s[j]);
                    continue;
                }
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
            }
        }
        cutdp.assign(n + 1, 1e8);
        cutdp[n] = -1;
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(dp[i][j]){
                    cutdp[i] = min(cutdp[i], 1 + cutdp[j+1]);
                }
            }
        }
        return cutdp[0];
    }
};