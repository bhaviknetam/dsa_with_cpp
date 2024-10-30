class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) {
            return (nums[0]==target)?0:-1;
        }
        int idx = 0, lo = 0, hi = n - 1;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] > nums[n-1]){
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
        idx = lo;
        if (target >= nums[idx] && target <= nums[n - 1]) {
            lo = idx;
            hi = n - 1;
        } else {
            lo = 0;
            hi = idx - 1;
        }
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        
        return -1;
    }
};