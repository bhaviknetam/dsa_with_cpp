class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> m;
        while(i < n){
            while(m.count(s[i])){
                m.erase(s[j]);
                j++;
            }
            m[s[i]] = i;
            ans = max(ans, (int)m.size());
            i++;
        }
        return ans;
    }
};