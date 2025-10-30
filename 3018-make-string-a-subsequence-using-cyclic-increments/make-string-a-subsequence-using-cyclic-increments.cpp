class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // we will take str2 "ad" str1 = "za"
        // first process a, i will check if there is a or z in str1
        // last index = 0
        // second process d, i will check for d or c greater than last index in str1
        map<char, set<int>> mp;
        int n = str1.size(), m = str2.size();
        for(int i = 0; i < n; i++){
            mp[str1[i]].insert(i);
        }
        int last = -1;
        for(int i = 0; i < m; i++){
            char c = str2[i];
            int nextindex = INT_MAX;
            if(mp.find(c) != mp.end()){
                auto nxtitr = mp[c].upper_bound(last);
                if(nxtitr != mp[c].end()){
                    nextindex = *nxtitr;
                }
            }
            char prev = (c == 'a') ? 'z' : c - 1;
            if(mp.find(prev) != mp.end()){
                auto nxtitr = mp[prev].upper_bound(last);
                if(nxtitr != mp[prev].end()){
                    nextindex = min(nextindex, *nxtitr);
                }
            }
            if(nextindex == INT_MAX){
                return false;
            }
            last = nextindex;
        }
        return true;
    }
};