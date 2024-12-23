class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int sum = 0, ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= target) {
                ans = min(ans, i - j + 1);
                sum -= nums[j++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};