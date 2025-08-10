class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct = 0, i = 0, n = nums.size();
        while(i < n){
            int j = i;
            while(j < n && nums[j]){
                j++;
            }
            ct = max(ct, j - i);
            i = j + 1;
        }
        return ct;
    }
};