class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = p.size(), n = s.size();
        if(m > n) return {};
        vector<int> count(26, 0), countWindow(26, 0);
        for(int i = 0; i < m; i++){
            count[p[i]-'a']++;
            countWindow[s[i]-'a']++;
        }
        vector<int> res;
        for(int i = m; i < n; i++){
            if(count == countWindow){
                res.push_back(i-m);
            }
            countWindow[s[i-m]-'a']--;
            countWindow[s[i]-'a']++;
        }
        if(count == countWindow) res.push_back(n-m);
        return res;
    }
};