class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n);
        leftMin[0] = nums[0];
        for(int i=1;i<n;i++){
            leftMin[i] = min(leftMin[i-1], nums[i]);
        }
        set<int> s;
        for(int i=n-1; i>=0; --i){
            auto it = s.upper_bound(leftMin[i]);
            if(it != s.end() && leftMin[i] != nums[i] && *it < nums[i]){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};