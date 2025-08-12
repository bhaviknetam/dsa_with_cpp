class Solution {
private: vector<vector<int>> ans;
public:
    void helper(vector<int>& curr, vector<int>& nums, vector<bool>& vis){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(vis[i]) continue;
            vis[i] = true;
            curr.push_back(nums[i]);
            helper(curr, nums, vis);
            curr.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        vector<int> curr;
        helper(curr, nums, vis);
        return ans;
    }
};