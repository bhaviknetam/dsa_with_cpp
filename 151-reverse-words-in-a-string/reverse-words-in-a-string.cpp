class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = n - 1;
        string ans;
        while(i >= 0){
            if(s[i] == ' '){
                i--;
                continue;
            }
            string t;
            int j = i;
            while(j >= 0 && s[j] != ' '){
                t.push_back(s[j]);
                j--;
            }
            reverse(t.begin(), t.end());
            ans += t;
            ans.push_back(' ');
            i = j;
        }
        ans.pop_back();
        return ans;
    }
};