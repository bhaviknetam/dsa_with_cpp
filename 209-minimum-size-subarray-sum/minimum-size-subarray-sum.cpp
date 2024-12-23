class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        queue<int> q;
        int sum = 0, ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            q.push(nums[i]);
            sum += nums[i];
            while (sum >= target) {
                ans = min(ans, (int)q.size());
                sum -= q.front();
                q.pop();
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};