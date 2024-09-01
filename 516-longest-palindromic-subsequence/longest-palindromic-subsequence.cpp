class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> next(n, 0), cur(n, 0);
        next[n-1] = 1;
        for(int i = n - 2; i >=0; i--){
            for(int j = i; j < n; j++){
                if(i == j){
                    cur[j] = 1;
                    continue;
                }
                if(s[i] == s[j]){
                    cur[j] = 2 + next[j-1];
                }else{
                    cur[j] = max(next[j], cur[j-1]);
                }
            }
            next = cur;
        }
        return next[n-1];
    }
};