class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long orgSum = (n * 1LL * (n-1))/2;
        if(sum == orgSum) return n;
        return n - (sum - orgSum);
    }
};