class Solution {
private: vector<vector<int>> s;
public:
    void helper(int i, vector<int>& curr, vector<int>& nums){
        if(i == nums.size()){
            s.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        helper(i + 1, curr, nums);
        curr.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        helper(i + 1, curr, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        helper(0, curr, nums);
        return s;
    }
};