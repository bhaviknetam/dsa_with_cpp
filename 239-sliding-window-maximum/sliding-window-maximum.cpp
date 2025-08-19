#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

using ordered_map = tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ordered_map m;
        for(int i = 0; i < k; i++){
            m[nums[i]]++;
        }
        // cout << m.size() <<';';
        vector<int> ans;
        ans.push_back(m.begin()->first);
        for(int i = k; i < nums.size(); i++){
            m[nums[i]]++;
            if(m[nums[i-k]] == 1) m.erase(nums[i-k]);
            else m[nums[i-k]]--;
            ans.push_back(m.begin()->first);
        }
        return ans;
    }
};