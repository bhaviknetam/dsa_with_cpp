class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<long long, int> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]] = i;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    long long comp = target * 1ll - nums[i] * 1ll -
                                     nums[j] * 1ll - nums[k] * 1ll;
                    if (m.count(comp) && m[comp] > k) {
                        ans.push_back({nums[i], nums[j], nums[k], (int)comp});
                    }
                    k = m[nums[k]];
                }
                j = m[nums[j]];
            }
            i = m[nums[i]];
        }
        return ans;
    }
};