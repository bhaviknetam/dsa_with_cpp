class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int min_so_far = nums[0], max_so_far = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int prod1 = min_so_far * nums[i];
            int prod2 = max_so_far * nums[i];
            min_so_far = min({nums[i], prod1, prod2});
            max_so_far = max({nums[i], prod1, prod2});
            ans = max(ans, max_so_far);
        }
        return ans;
    }
};