class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(high - low > 1){
            int mid = low + (high - low)/2;
            if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        if(nums[low]==target) return low;
        else if(nums[high]==target)return high;
        else return -1;
    }
};