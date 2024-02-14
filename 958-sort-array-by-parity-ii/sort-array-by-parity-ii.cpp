class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int evenIndex = 0, oddIndex = 1;
        vector<int> ans(nums.size(), 0);
        for(int& i : nums){
            if(i & 1){
                ans[oddIndex] = i;
                oddIndex += 2;
            } else {
                ans[evenIndex] = i;
                evenIndex += 2;
            }
        }
        return ans;
    }
};