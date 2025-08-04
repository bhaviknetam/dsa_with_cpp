class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int ct =0;
        for(int i = 0; i < nums.size(); i++){
            if(ct == 0) candidate = nums[i];
            if(nums[i] == candidate) ct++;
            else ct--;
        }
        return candidate;
    }
};