class Solution {
public:
    int superEggDrop(int n, int k){
        vector<int> dp(n + 1, 0);
        int m = 0;
        for(; dp[n] < k; m++) {
            for(int f = n; f >= 1; f--){
                dp[f] += 1 + dp[f-1];
            }
        }
        return m;
    }
};