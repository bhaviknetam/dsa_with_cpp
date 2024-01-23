class Solution {
public:
    int dp[405];
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return func(0, n-1, nums);
    }

    int func(int idx, int end, vector<int>& nums){
        if(idx > end) return 0;
        if(dp[idx] != -1) return dp[idx];
        int currSkipped = func(idx+1, end, nums);
        int currAdded = func(idx+2, end, nums) + nums[idx];
        return dp[idx] = max(currSkipped, currAdded);
    }
};