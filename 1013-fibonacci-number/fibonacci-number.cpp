class Solution {
public:
const int N = 100;
    vector<int> dp;
    int fib(int n) {
        dp.resize(N,0);
        if(dp[n]!=0) return dp[n];
        if(n == 0) return 0;
        if(n == 1 ) return 1;
        return dp[n] =  fib(n-1) + fib(n-2);
    }
};