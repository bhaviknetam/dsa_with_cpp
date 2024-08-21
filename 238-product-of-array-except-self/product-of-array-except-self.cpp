class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = nums[0];
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            nums[i] = nums[i] * nums[i + 1];
        }
        int temp = 1;
        for (int i = 0; i < n - 1; i++) {
            int t = ans[i];
            ans[i] = nums[i + 1] * temp;
            temp = t;
        }
        ans[n - 1] = temp;
        return ans;
    }
};