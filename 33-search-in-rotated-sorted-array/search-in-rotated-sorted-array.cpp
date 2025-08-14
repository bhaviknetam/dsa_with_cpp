class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1, r = n - 1;
        while(r - l > 1){
            int mid = l + ((r - l) >> 1);
            if(nums[mid] > nums[n-1]) l = mid;
            else r = mid;
        }
        if(target <= nums[n-1]) l = r, r = n;
        else l = 0;
        while(r - l > 1){
            int mid = l + ((r-l)>>1);
            if(nums[mid] <= target) l = mid;
            else r = mid;
        }
        return (nums[l] == target ? l : -1);
    }
};