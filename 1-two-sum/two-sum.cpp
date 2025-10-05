class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //array a[0]>>>x  tsarget y arrry 1-  n-1  
        for(int i=0; i < nums.size(); ++i){
            nums[i];
            for(int j=i+1; j < nums.size();++j){
                if(nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};
