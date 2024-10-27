class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[n-1] < target) return n;
        if(nums[0] >= target) return 0;
        int lo = 0, hi = n-1, ans = 0;
        while(hi - lo > 1){
            int mid = (lo + hi) >> 1;
            if(nums[mid] < target) lo = mid;
            else if(nums[mid] > target) hi = mid - 1;
            else return mid;
        }
        if(nums[hi] < target) return hi + 1;
        return lo + 1;
    }
};