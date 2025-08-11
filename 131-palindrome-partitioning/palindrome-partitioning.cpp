class Solution {
private: vector<vector<string>> ans;
public:
    bool isPalindrome(string& s){
        int i = 0, j = s.size()-1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void helper(int i, vector<string>& p, string s){
        if(i == s.size()){
            if(isPalindrome(p.back()))
                ans.push_back(p);
            return;
        }
        if(p.empty() || isPalindrome(p.back())){
            p.push_back(string() + s[i]);
            helper(i+1, p, s);
            p.pop_back();
        }
        if(i != 0){
            p.back().push_back(s[i]);
            helper(i+1, p, s);
            p.back().pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> p;
        helper(0, p, s);
        return ans;
    }
};