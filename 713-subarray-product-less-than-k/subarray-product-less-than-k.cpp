class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (nums.empty() || k == 0)
            return 0;
        int i = 0, j = 0, ans = 0, prod = 1;
        while (j < nums.size() and j >= i) {
            prod *= nums[j];
            while (prod >= k) {
                prod /= nums[i];
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        if(ans < 0) return 0;
        return ans;
    }
};