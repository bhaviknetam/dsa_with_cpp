class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec = {1};
        vec.insert(vec.end(), nums.begin(), nums.end());
        vec.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int i = n; i >= 1; i--){
            for(int j = i; j <= n; j++){
                for(int k = i; k <= j; k++){
                    int points = vec[i-1] * vec[k] * vec[j+1];
                    dp[i][j] = max(dp[i][j], dp[i][k-1]+dp[k+1][j]+points);
                }
            }
        }
        return dp[1][n];
    }
};