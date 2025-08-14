class Solution {
private: vector<int> dp;
public:
    bool helper(int start, string s, unordered_set<string>& dict){
        int n = s.size();
        if(start == n){
            return true;
        }
        if(dp[start] != -1) return dp[start];
        string t;
        for(int i = start; i < n; i++){
            t.push_back(s[i]);
            if(dict.count(t) && helper(i + 1, s, dict)){
                return dp[start] = true;
            }
        }
        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        dp.resize(s.size() + 1, -1);
        return helper(0, s, dict);
    }
};