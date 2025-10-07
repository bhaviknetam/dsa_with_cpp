class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lo = lower_bound(nums.begin(),nums.end(),target);
        if(lo == nums.end() || *lo != target){
            return {-1, -1};
        }
        auto hi = --upper_bound(nums.begin(), nums.end(), target);
        int l = lo - nums.begin();
        int h = hi - nums.begin();
        return {l, h};
    }
};