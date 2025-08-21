class Solution {
public:
    int RabinKarp(string text, string pattern){
        int m = pattern.size();
        int n = text.size();
        int d = 31, q = 1e9 + 7;
        long long p = 0, t = 0;
        long long h = 1;
        for(int i = 1; i < m; i++) h = (h * d) % q;
        for(int i = 0; i < m; i++){
            p = (p * d + pattern[i]) % q;
            t = (t * d + text[i]) % q;
        }
        for(int i = 0; i <= n - m; i++){
            if(p == t){
                int j = 0;
                for(; j < m; j++){
                    if(text[i+j] != pattern[j]) break;
                }
                if(j == m){
                    return true;
                }
            }
            if(i < n- m){
                t = (d * (t - text[i] * h) + text[i + m]) % q;
                if(t < 0) t = t + q;
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        int m = b.size();
        int n = a.size();
        int ct = 1;
        string text = a;
        while(text.size() < b.size()){
            ct++;
            text += a;
        }
        if(text == b) return ct;
        if(RabinKarp(text, b)) return ct;
        if(RabinKarp(text + a, b)) return ct + 1;
        return -1;
    }
};