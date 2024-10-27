class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < n - 2; k++){
            if(k > 0 && nums[k] == nums[k-1])continue;
            int target = -nums[k];
            int i = k + 1, j = n - 1;
            while(i < j){
                if(target - nums[j] > nums[i]) i++;
                else if(target - nums[i] < nums[j]) j--;
                else{
                    ans.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) i++;
                    while (i < j && nums[j] == nums[j - 1]) j--;
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};