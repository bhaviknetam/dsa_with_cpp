class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(char& c: s){
            m[c]++;
        }
        bool odd=false;
        int ans=0;
        for(auto& it : m){
            if(!(it.second&1)){
                ans+=it.second;
            }else {
                ans+=(it.second-1);
                odd=true;
            }
        }
        if(odd) return ans+1;
        return ans;
    }
};