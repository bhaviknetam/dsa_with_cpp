class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        stack<int> pos, neg;
        vector<int> ans;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] >= 0)
                pos.push(nums[i]);
            else
                neg.push(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i & 1) {
                ans.push_back(neg.top());
                neg.pop();
            } else {
                ans.push_back(pos.top());
                pos.pop();
            }
        }
        return ans;
    }
};