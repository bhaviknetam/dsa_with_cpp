class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, ans = 0;
        for (; end < nums.size(); end++) {
            if (nums[end] == 0)
                k--;
            if (k < 0) {
                if (nums[start] == 0)
                    k++;
                start++;
            }
            if (k >= 0)
                ans = max(ans, end - start+1);
        }
        return ans;
    }
};