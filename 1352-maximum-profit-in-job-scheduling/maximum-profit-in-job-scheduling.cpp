class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = endTime.size();
        vector<pair<int, int>> endWithIdx(n);
        for(int i = 0 ; i < n;i++) endWithIdx[i] = {endTime[i], i};
        sort(endWithIdx.begin(), endWithIdx.end());
        vector<int> dp(n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int idx = endWithIdx[i-1].second;
            int start = startTime[idx];
            int end = endTime[idx];
            int value = profit[idx];
            auto it = upper_bound(endWithIdx.begin(), endWithIdx.end(), make_pair(start, INT_MAX));
            int prev = 0;
            if(it != endWithIdx.begin()){
                prev = (it - endWithIdx.begin());
            }
            dp[i] = max(dp[i-1], dp[prev] + value);
        }
        return dp[n];
    }
};