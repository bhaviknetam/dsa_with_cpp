class Solution {
public:
    void LPS(string& needle, vector<int>& lps){
        int n = needle.size();
        lps.resize(n);
        lps[0] = 0;
        int len = 0, i = 1;
        while(i < n){
            if(needle[i] == needle[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) return -1;
        if(haystack == needle) return 0;
        vector<int> lps;
        LPS(needle, lps);
        int i = 0, j = 0;
        int n = haystack.size(), m = needle.size();
        while(i < n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
                if(j == m){
                    return i - j;
                }
            }else{
                if(j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return -1;
    }
};