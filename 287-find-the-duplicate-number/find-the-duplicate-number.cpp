class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int x = abs(nums[i]) - 1;
            if(nums[x] < 0) return abs(nums[i]);
            nums[x] = (-1)*nums[x];
        }
        return -1;
    }
};