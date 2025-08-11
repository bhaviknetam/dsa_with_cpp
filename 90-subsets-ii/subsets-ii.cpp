#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t h = v.size();
        for (int x : v) {
            h ^= (x + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2));
        }
        return h;
    }
};

class Solution {
private: gp_hash_table<vector<int>, null_type, VectorHash> s;
public:
    void helper(int i, vector<int>& curr, vector<int>& nums){
        if(i == nums.size()){
            s.insert(curr);
            return;
        }
        curr.push_back(nums[i]);
        helper(i + 1, curr, nums);
        curr.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        helper(i + 1, curr, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        helper(0, curr, nums);
        return vector<vector<int>>(s.begin(), s.end());
    }
};