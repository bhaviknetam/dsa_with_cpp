class Solution {
private: vector<vector<int>> ans;
public:
    void backtrack(int i, int target, vector<int> curr, vector<int>& candidates){
        if(target < 0) return;
        if(target == 0){
            ans.push_back(curr);
        }
        for(int j = i; j < candidates.size(); j++){
            curr.push_back(candidates[j]);
            backtrack(j, target - candidates[j], curr, candidates);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        backtrack(0, target, v, candidates);
        return ans;
    }
};