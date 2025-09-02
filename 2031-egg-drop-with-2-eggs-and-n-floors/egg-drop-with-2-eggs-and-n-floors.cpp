class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(3, 0);
        int m = 0;
        for(;dp[2] < n; m++){
            for(int e = 2; e >= 1; e--){
                dp[e] += 1 + dp[e - 1];
            }
        }
        return m;
    }
};