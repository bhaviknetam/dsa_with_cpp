class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        for(int i = 0; i < k; i++){
            while(!d.empty() && nums[d.back()] <= nums[i]){
                d.pop_back();
            }
            d.push_back(i);
        }
        vector<int> ans;
        ans.push_back(nums[d.front()]);
        for(int i = k; i < nums.size(); i++){
            if(d.front() == i - k) d.pop_front();
            while(!d.empty() && nums[d.back()] <= nums[i]){
                d.pop_back();
            }
            d.push_back(i);
            ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};