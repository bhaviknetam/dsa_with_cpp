class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool OneIsPresent = false;
        for(int& num : nums){
            if(num==1)OneIsPresent = true;
            if(num<=0) num=1;
        }
        if(!OneIsPresent) return 1;
        for(int& num : nums){
            int val = abs(num)-1;
            if(val<nums.size() and nums[val] >0){
                nums[val]*=-1;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)return i+1;
        }
        return nums.size()+1;
    }
};