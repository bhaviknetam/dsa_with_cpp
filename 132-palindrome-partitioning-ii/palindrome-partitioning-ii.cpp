class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
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