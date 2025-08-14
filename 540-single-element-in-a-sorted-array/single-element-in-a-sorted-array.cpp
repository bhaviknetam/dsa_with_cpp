class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size();
        while(r - l > 1){
            int mid = l + ((r - l) >> 1);
            if(mid & 1) mid--;
            if(nums[mid] == nums[mid + 1]) l = mid + 2;
            else r = mid + 1;
        }
        return nums[l];
    }
};