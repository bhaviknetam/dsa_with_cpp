class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int, greater<int>> window;
        for(int i=0;i<k;i++){
            window.insert(nums[i]);
        }
        ans.push_back(*window.begin());
        for(int i=k;i<nums.size();i++){
            auto it = window.find(nums[i-k]);
            window.erase(it);
            window.insert(nums[i]);
            ans.push_back(*window.begin());
        }
        return ans;
    }
};