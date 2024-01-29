class Solution {
public:
    int dp[1005][1005];
    int subseq(int i, int j, string& s, string& t) {
        int n = s.length();
        int m = t.length();
        if(j == m) return 1;
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int total =0;
        if (s[i] == t[j])
            total = subseq(i + 1, j + 1, s, t) + subseq(i + 1, j, s, t);
        else total = subseq(i+1, j , s, t);
        return dp[i][j] = total;
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return subseq(0,0, s, t);
    }
};