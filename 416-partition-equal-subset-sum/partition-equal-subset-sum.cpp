class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 1 or accumulate(nums.begin(), nums.end(), 0) & 1)
            return false;
        map<int, int> dp;
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            map<int, int> new_dp(dp);
            for (auto& [curr_sum, count] : dp) {
                int new_sum = curr_sum + nums[i];
                if (new_dp.find(new_sum) == new_dp.end()) {
                    new_dp[new_sum] = count + 1;
                }
            }
            swap(new_dp, dp);
        }
        auto it = prev(dp.end());
        int half_sum = it->first / 2;
        if (dp.count(half_sum))
            return true;
        return false;
    }
};