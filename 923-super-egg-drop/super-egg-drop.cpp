class Solution {
public:
    vector<vector<int>> dp;
    int superEggDrop(int n, int k){
        dp.assign(n+1, vector<int>(k+1, -1));
        return func(n, k);
    }
    
    int func(int n, int k) {
        if(k == 0 or k == 1) return k;
        if(n == 1) return k;
        if(dp[n][k] != -1) return dp[n][k];
        int mini = INT_MAX;
        int l = 1, r = k;
        while(l <= r){
            int mid = l + ((r - l) >> 1);
            int left = func(n - 1, mid - 1);
            int right = func(n, k - mid);
            int temp = 1 + max(left, right);
            if(right > left) l = mid + 1;
            else r = mid - 1;
            mini = min(mini, temp);
        }
        return dp[n][k] = mini;
    }
};