class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < n - 2; k++){
            int target = -nums[k];
            int i = k + 1, j = n - 1;
            while(i < j){
                if(target - nums[j] > nums[i]) i++;
                else if(target - nums[i] < nums[j]) j--;
                else{
                    ans.insert({nums[k], nums[i], nums[j]});
                    i++;
                    j--;
                }
            }
        }
        vector<vector<int>> v;
        for(auto& vec : ans) v.push_back(vec);
        return v;
    }
};