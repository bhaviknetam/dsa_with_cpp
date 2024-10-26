class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0, ans = INT_MIN;
        for(int& num : nums){
            currsum += num;
            ans = max(ans, currsum);
            currsum = max(0, currsum);
        }
        return ans;
    }
};