class Solution {
public:
    bool check(string& s){
        int n = s.size();
        int l = 0, r = n - 1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
    void helper(int start, string& s, vector<string>& ans,
    vector<vector<string>>& res){
        if(start == s.size()){
            res.push_back(ans);
            return;
        }
        string t;
        for(int i = start; i < s.size(); i++){
            t.push_back(s[i]);
            if(check(t)){
                ans.push_back(t);
                helper(i + 1, s, ans, res);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        helper(0, s, ans, res);
        return res;
    }
};