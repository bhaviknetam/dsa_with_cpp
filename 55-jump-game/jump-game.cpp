class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0] == 0 && nums.size() > 1) return false;
        bool ans= false;
        int maxi = nums[0];
        for(int i = 0;i<nums.size()-1;i++){
            nums[i] = i + nums[i];
           // if(nums[i] >= nums.size() - 1) ans= true;
        }
        int j=0;
        while(j <= maxi){
            if(nums[j] > maxi){
                maxi = nums[j];
            }
            if(maxi >= nums.size() - 1){
                ans = true;
                break;
            }
            j++;
        }
        return ans;
    }
};