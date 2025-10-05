class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //array a[0]>>>x  tsarget y arrry 1-  n-1 
        unordered_map<int, int> m;
        for(int i=0; i < nums.size(); ++i){
            int comp = target - nums[i];
            if(m.find(comp) != m.end()){
                return {m[comp], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
