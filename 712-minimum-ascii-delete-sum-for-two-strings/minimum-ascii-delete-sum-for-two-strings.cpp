class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m+1, 0));
        bool ismatched = (s1[0] == s2[0]) ? true : false;
        dp[1][1] = (s1[0] == s2[0]) ? 0 : (int)(s1[0] + s2[0]);
        for (int i = 2; i <= n; i++) {
            if (s1[i - 1] == s2[0] and !ismatched)
                dp[i][1] = dp[i - 1][1] - s2[0], ismatched = true;
            else
                dp[i][1] = dp[i - 1][1] + s1[i - 1];
        }
        ismatched = (s1[0] == s2[0]) ? true : false;
        for (int i = 2; i <= m; i++) {
            if (s2[i - 1] == s1[0] and !ismatched)
                dp[1][i] = dp[1][i - 1] - s1[0], ismatched = true;
            else
                dp[1][i] = dp[1][i - 1] + s2[i - 1];
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
            min(dp[i][j - 1] + s2[j - 1], dp[i - 1][j] + s1[i - 1]);
                }
            }
        }
        return dp[n][m];
    }
};