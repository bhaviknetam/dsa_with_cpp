class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    void subs(auto nums, int n, int m){
        if(n == m){
            ans.push_back(vec);
            return;
        }
        subs(nums + 1, n + 1, m);
        vec.push_back(*nums);
        subs(nums + 1, n+1, m);
        vec.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        subs(nums.begin(), 0, nums.size());
        return ans;
    }
};