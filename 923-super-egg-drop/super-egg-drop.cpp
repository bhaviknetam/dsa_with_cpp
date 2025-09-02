class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> dp(k + 1, 0);
        int m = 0;
        for(; dp[k] < n; m++){
            for(int e = k; e >= 1; e--){
                dp[e] += 1 + dp[e - 1];
            }
        }
        return m;
    }
};