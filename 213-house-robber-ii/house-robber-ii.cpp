class Solution {
public:
    int dp[1005];
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int a = robRange(nums, 0, n - 2);
        memset(dp, -1, sizeof(dp));
        int b = robRange(nums, 1, n - 1);

        return max(a, b);
    }

    int robRange(vector<int>& nums, int start, int end) {
        if(start > end) return 0;
        if(dp[start] != -1) return dp[start];
        int currSkipped = robRange(nums, start +1, end);
        int currRobbed = robRange(nums, start + 2, end) + nums[start];

        
        return dp[start] = max(currRobbed, currSkipped);
    }
};
