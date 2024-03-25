class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int val = abs(nums[i]) - 1;
            if (nums[val] < 0) {
                ans.push_back(val + 1);
            } else
                nums[val] *= -1;
        }
        return ans;
    }
};