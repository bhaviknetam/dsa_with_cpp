class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = (1 << 25) - 1;
        for(int i = 0; i < n; i++){
            if(nums[i] != i) ans &= nums[i];
        }
        if(ans > 1e5) return 0;
        return ans;
    }
};