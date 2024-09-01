class Solution {
public:
    int countSubstrings(string s) {
        int n =s.size();
        vector<int> next(n, 0), cur(n, 0);
        next[n - 1] = 1;
        int ans = 1;
        for(int i = n-2; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i == j){
                    cur[j] = 1;
                }
                else if(j - i == 1){
                    if(s[i] == s[j])
                        cur[j] = 1;
                }else{
                    if(s[i]==s[j]){
                        cur[j] = next[j-1];
                    }
                }
                ans += cur[j];
            }
            next = cur;
            fill(cur.begin(), cur.end(), 0);
        }
        return ans;
    }
};