class Solution {
private: vector<vector<int>> ans;
public:
    void backtrack(int i, int target, vector<int> curr, vector<int>& candidates){
        if(target < 0) return;
        if(target == 0){
            ans.push_back(curr);
        }
        for(int j = i; j < candidates.size(); j++){
            int c = candidates[j];
            if(target < c) continue;
            curr.push_back(c);
            backtrack(j, target - c, curr, candidates);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        backtrack(0, target, v, candidates);
        return ans;
    }
};