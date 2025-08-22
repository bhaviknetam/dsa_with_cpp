class Solution {
public:
    void LCP(string& s, vector<int>& lcp){
        int n = s.size();
        int i = 1, len = 0;
        lcp[0] = 0;
        while(i < n){
            if(s[i] == s[len]){
                len++;
                lcp[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lcp[len - 1];
                }else{
                    lcp[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        t = s + "$" + t;
        vector<int> lcp(t.size());
        LCP(t, lcp);
        int n = s.size();
        string ans = s;
        reverse(ans.begin(), ans.end());
        int ct = n - lcp.back();
        for(int i = n - ct; i < n; i++) ans.push_back(s[i]);
        return ans;
    }
};