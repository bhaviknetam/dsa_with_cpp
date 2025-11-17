class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1) % (k-1) != 0) return -1;
        vector<int> pref(n + 1);
        pref[0] = 0;
        for(int i = 1; i <= n; i++){
            pref[i] = pref[i-1] + stones[i-1];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = n - k; i >= 0; i--){
            for(int j = i + k - 1; j < n; j++){
                dp[i][j] = INT_MAX;
                for(int mid = i; mid < j; mid+=(k-1)){
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid+1][j]);
                }
                if((j - i) % (k - 1) == 0){
                    dp[i][j] += pref[j+1] - pref[i];
                }
            }
        }
        return dp[0][n-1];
    }
};