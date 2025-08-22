class Solution {
public:
    int RabinKarp(int x, string s){
        int n = s.size();
        long long d = 31;
        long long h1 = 1, h2 = 1;
        long long q1 = 1e9 + 7, q2 = 1e9 + 9;
        for(int i = 1; i < x; i++){
            h1 = (h1 * d) % q1;
            h2 = (h2 * d) % q2;
        }
        unordered_set<long long> s1, s2;
        long long t1 = 0, t2 = 0;
        for(int i = 0; i < x; i++){
            t1 = (t1 * d + s[i]) % q1;
            t2 = (t2 * d + s[i]) % q2;
        }
        for(int i = 0; i <= n - x; i++){
            if(s1.count(t1) && s2.count(t2)){
                return i;
            }
            if(i < n- x){
                s1.insert(t1);
                s2.insert(t2);
                t1 = (d * (t1 - s[i] * h1) + s[i+x]) % q1;
                t2 = (d * (t2 - s[i] * h2) + s[i+x]) % q2;
                if(t1 < 0) t1 = t1 + q1;
                if(t2 < 0) t2 = t2 + q2;
            }
        }
        return -1;
    }
    string longestDupSubstring(string s) {
        int n = s.size();
        int l = 1, r = s.size();
        int sz = 0, start = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            int idx = RabinKarp(mid, s);
            if(idx != -1){ l = mid + 1; start = idx; sz = mid;}
            else r = mid - 1;
        }
        if(start == -1) return "";
        return s.substr(start, sz);
    }
};