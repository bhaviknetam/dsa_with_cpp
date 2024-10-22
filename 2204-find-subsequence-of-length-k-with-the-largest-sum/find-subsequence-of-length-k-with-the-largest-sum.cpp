class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
        for (int i = 0; i < n; i++)
            s.push({nums[i], i});
        int ct = 0;
        while (ct != n - k) {
            nums[s.top().second] = INT_MAX;
            s.pop();
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