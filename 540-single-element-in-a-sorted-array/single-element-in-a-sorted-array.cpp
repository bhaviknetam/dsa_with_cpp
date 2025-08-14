class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = l + ((r - l) >> 1);
            if(mid + 1 <= r && nums[mid] == nums[mid + 1]){
                if(!(mid & 1)) l = mid;
                else r = mid - 1;
            }
            else if(mid - 1 >= l && nums[mid] == nums[mid - 1]){
                if(!((mid + 1) & 1)) l = mid + 1;
                else r = mid;
            } else return nums[mid];
        }
        return l;
    }
};