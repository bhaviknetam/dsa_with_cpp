class Solution {
private:
    vector<vector<vector<int>>> dp;

public:
    int func(int idx, vector<int>& prices, bool bought, int k) {
        if (k == 0 || idx == prices.size()) return 0;
        if (dp[idx][bought][k] != -1) return dp[idx][bought][k];
        int ans = 0;

        if (bought) {
            ans = max(ans, prices[idx] + func(idx + 1, prices, 0 ,k - 1));
            ans = max(ans, func(idx + 1, prices, 1, k));
        } else {
            ans = max(ans, -prices[idx] + func(idx + 1, prices, 1, k));
            ans = max(ans, func(idx + 1, prices, 0, k));
        }
        
        return dp[idx][bought][k] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return func(0, prices, false, 2);
    }
};
