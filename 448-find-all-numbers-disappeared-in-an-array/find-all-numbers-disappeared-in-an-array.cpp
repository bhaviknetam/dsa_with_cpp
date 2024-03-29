class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> s;
        for(int i =0 ; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        for(int i =1; i<=nums.size(); i++){
            auto it = s.find(i);
            if(it == s.end()) ans.push_back(i);
        }
        return ans;
    }
};