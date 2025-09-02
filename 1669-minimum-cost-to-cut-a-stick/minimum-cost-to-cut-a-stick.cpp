class Solution {
private:
    vector<vector<int>> dp;
public:
    int func(int l, int r, vector<int>& cuts){
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = INT_MAX;
        for(int i = l + 1; i < r; i++){
            int cut = cuts[i];
            ans = min(ans, cuts[r] - cuts[l] + func(l, i, cuts) + func(i, r, cuts));
        }
        return dp[l][r] = (ans == INT_MAX ? 0 : ans);
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int k = cuts.size();
        dp.assign(k, vector<int>(k, -1));
        return func(0, k - 1, cuts);
    }
};