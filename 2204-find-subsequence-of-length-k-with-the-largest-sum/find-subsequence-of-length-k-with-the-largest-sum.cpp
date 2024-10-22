class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        set<pair<int, int>> s;
        for (int i = 0; i < n; i++)
            s.insert({nums[i], i});
        int ct = 0;
        while (ct != n - k) {
            nums[s.begin()->second] = INT_MAX;
            s.erase(s.begin());
            ct++;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(nums[i]!=(int)INT_MAX){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};