class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        vector<vector<int>> dp(sz + 1, vector<int>(sz + 1, 0));
        for (int i = 0; i < sz; i++) {
            dp[i][i] = 1;
        }
        int ans = 1, idx = -1;
        for (int i = sz - 1; i >= 0; i--) {
            for (int j = i + 1; j < sz; j++) {
                if (j - i == 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                    }
                } else {
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j]) {
                    if(ans < j - i+1){
                        ans = j-i+1;
                        idx=i;
                    }
                }
            }
        }
        if(idx!=-1)
        return s.substr(idx, ans);
        return s.substr(0, 1);
    }
};