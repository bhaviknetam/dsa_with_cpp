class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = l + ((r - l) >> 1);
            if(nums[mid] > nums[n-1]) l = mid + 1;
            else r = mid - 1;
        }
        if(target <= nums[n-1]) l = r + 1, r = n - 1;
        else l = 0;
        while(l <= r){
            int mid = l + ((r-l)>>1);
            if(nums[mid] < target) l = mid + 1;
            else if(nums[mid] > target) r = mid - 1;
            else return mid;
        }
        return -1;
    }
};