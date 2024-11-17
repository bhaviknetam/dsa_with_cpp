class Solution {
private: vector<vector<vector<int>>> dp;
public:
    int func(int idx, vector<int>& prices, bool bought,int k){
        int ans = 0;
        if(k == 0 || idx == prices.size()) return 0;
        if(dp[idx][bought][k] != -1) return dp[idx][bought][k];
        if(bought){
            ans = max(ans, prices[idx] + func(idx + 1,prices, false,k - 1));
            ans = max(ans,func(idx + 1, prices, true, k));
        }else{
            ans=max(ans,-prices[idx]+func(idx + 1, prices, true, k));
            ans=max(ans,func(idx + 1, prices, false, k));
        }
        return dp[idx][bought][k] = ans;
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return func(0, prices, false, 2);
    }
};