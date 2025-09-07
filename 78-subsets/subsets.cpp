class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int N = 1 << n;
        for(int mask = 0; mask < N; mask++){
            vector<int> v;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    v.push_back(nums[i]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};