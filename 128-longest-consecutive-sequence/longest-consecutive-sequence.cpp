class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        unordered_map<int, int> m;
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(!s.count(nums[i])) continue;
            int ct = 0;
            int j = nums[i];
            while(s.count(j)){
                j++;
                ct++;
            }
            for(int k = nums[i]; k < j; k++){
                s.erase(k);
            }
            ct += m[j];
            m[nums[i]] = ct;
            ans = max(ans, ct);
        }
        return ans;
    }
};