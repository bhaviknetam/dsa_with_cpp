class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool flip = false;
        for(int i = 0; i < n; i++){
            if((!flip && !nums[i]) || (flip && nums[i])){
                ans++;
                flip = !flip;
            }
        }
        return ans;
    }
};