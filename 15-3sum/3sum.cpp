class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        unordered_map<int,int> m;
        for(int i = 0; i < n; i++){
            m[nums[i]] = i;
        }
        for(int i = 0; i < n-2; i++){
            if(nums[i] > 0) break;
            for(int j = i + 1; j < n - 1; j++){
                int target = -nums[i]-nums[j];
                if(m.count(target) && m[target] > j){
                    ans.push_back({nums[i], nums[j], target});
                }
                j = m[nums[j]];
            }
            i = m[nums[i]];
        }
        return ans;
    }
};