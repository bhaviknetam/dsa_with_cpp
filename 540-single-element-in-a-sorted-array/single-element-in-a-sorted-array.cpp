class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            if(l == r) return nums[l];
            int mid = (l + r) >> 1;
            if(mid & 1) mid--;
            if(nums[mid] == nums[mid + 1]) l = mid + 2;
            else r = mid;
        }
        return -1;
    }
};