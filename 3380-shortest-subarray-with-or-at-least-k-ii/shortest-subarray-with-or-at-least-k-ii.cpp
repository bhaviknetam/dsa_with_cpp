class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> countArr(n + 1, vector<int>(31, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 31; j++) {
                countArr[i][j] += countArr[i - 1][j];
                if ((nums[i - 1] >> j) & 1)
                    countArr[i][j]++;
            }
        }
        int totalOR = 0, ans = INT_MAX;
        int j = 1;
        for (int i = 1; i <= n; i++) {
            totalOR |= nums[i - 1];
            while (j <= i && totalOR >= target) {
                ans = min(ans, i - j + 1);
                int nextOR = 0;
                for (int k = 0; k < 31; k++) {
                    int ct = countArr[i][k] - countArr[j][k];
                    if (ct > 0)
                        nextOR |= (1 << k);
                }
                totalOR = nextOR;
                j++;
            }
        }
        return (ans != INT_MAX) ? ans : -1;
    }
};