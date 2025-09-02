class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int k = cuts.size();
        vector<vector<int>> dp(k, vector<int>(k, 0));
        for(int i = k - 3; i >= 0; i--){
            for(int j = i + 2; j < k; j++){
                dp[i][j] = INT_MAX;
                for(int cut = i + 1; cut < j; cut++){
                    dp[i][j] = min(dp[i][j], cuts[j]-cuts[i]+dp[i][cut]+dp[cut][j]);
                }
            }
        }
        return dp[0][k-1];
    }
};