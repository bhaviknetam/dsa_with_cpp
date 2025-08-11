class Solution {
private: set<vector<int>> s;
public:
    void helper(int i, vector<int>& curr, vector<int>& nums){
        if(i == nums.size()){
            vector<int> t = curr;
            sort(t.begin(), t.end());
            s.insert(t);
            return;
        }
        helper(i+1, curr, nums);
        curr.push_back(nums[i]);
        helper(i+1, curr, nums);
        curr.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        helper(0, curr, nums);
        return vector<vector<int>>(s.begin(), s.end());
    }
};