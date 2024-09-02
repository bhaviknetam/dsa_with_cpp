class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        ans.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
            if(it == ans.end()){
                ans.push_back(nums[i]);
            }else{
                int idx = it - ans.begin();
                ans[idx] = nums[i];
            }
        }
        return ans.size();
    }
};