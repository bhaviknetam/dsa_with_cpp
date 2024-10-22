class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> v = nums;
        sort(v.rbegin(), v.rend());
        multiset<int> m;
        for(int i = 0; i < k; i++){
            m.insert(v[i]);
        }
        vector<int> ans;
        for(int i = 0; i < (int)nums.size(); i++){
            if(m.count(nums[i])){
                ans.push_back(nums[i]);
                m.erase(m.find(nums[i]));
            }
        }
        return ans;
    }
};