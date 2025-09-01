class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty()) return true;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        int k = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
        dp[0][0] = true;
        for(int i = 0; i < n; i++){
            dp[i+1] = dp[i];
            for(int j = 0; j <= k; j++){
                if(dp[i][j] && (j + nums[i] <= k)){
                    dp[i+1][j+nums[i]] = true;
                }
            }
        }
        return dp[n][k];
    }
};