class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1, r = n - 1;
        while(r - l > 1){
            int mid = l + ((r-l)>>1);
            if(nums[mid] >= nums[l + 1] && nums[mid] >= nums[r]){
                l = mid;
            }else{
                r = mid;
            }
        }
        int k = n - r;
        k %= n;
        // cout << r <<';';
        l = r, r = n + l;
        while(r - l > 1){
            int mid = l + ((r-l)>>1);
            if(nums[mid % n] <= target) l = mid;
            else r = mid;
        }
        l %= n;
        return (nums[l] == target) ? l : -1;
    }
};