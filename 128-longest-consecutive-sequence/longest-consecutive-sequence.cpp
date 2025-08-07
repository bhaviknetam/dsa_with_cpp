class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (int num : s) {
            if (s.find(num - 1) == s.end()) {
                int j = num;
                int len = 1;
                while (s.count(j + 1)) {
                    j++;
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};