class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0, j = 0;
        
        while (i < n && s[i] == ' ') i++;
        
        while (i < n) {
            if (s[i] != ' ') {
                s[j++] = s[i++];
            } 
            else {
                while (i < n && s[i] == ' ') i++;
                if (i < n) s[j++] = ' ';
            }
        }
        
        s.resize(j);
        
        reverse(s.begin(), s.end());
        
        int start = 0;
        for (int k = 0; k <= (int)s.size(); k++) {
            if (k == s.size() || s[k] == ' ') {
                reverse(s.begin() + start, s.begin() + k);
                start = k + 1;
            }
        }
        
        return s;
    }
};
