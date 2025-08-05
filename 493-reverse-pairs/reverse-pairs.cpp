#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ordered_set = tree<long long, null_type, less_equal<long long>,
                         rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set os;
        int ans = 0;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            ans += os.order_of_key((long long)nums[i]);
            os.insert((long long)2 * nums[i]);
        }

        return ans;
    }
};