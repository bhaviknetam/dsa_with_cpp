class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int zero = -1;
        int missing = n;
        for (int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]);
            if (x == n) {
                missing = 0;
                continue;
            }
            if (nums[x] == 0) {
                zero = x;
                continue;
            } else {
                nums[x] = -nums[x];
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == zero)
                continue;
            if (nums[i] >= 0)
                return i;
        }
        return missing;
    }
};