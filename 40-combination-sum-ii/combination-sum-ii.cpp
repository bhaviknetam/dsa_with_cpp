class Solution {
private: vector<vector<int>> ans;
public:
    void backtrack(int i, int target, vector<int>& v, vector<int>& candidates){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(i == candidates.size() || target < 0) return;
        if(target >= candidates[i]){
            v.push_back(candidates[i]);
            backtrack(i+1, target-candidates[i],v,candidates);
            v.pop_back();
        }
        while(i+1<candidates.size() && candidates[i]==candidates[i+1])
            i++;
        backtrack(i+1, target, v, candidates);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        backtrack(0, target, v, candidates);
        return ans;
    }
};