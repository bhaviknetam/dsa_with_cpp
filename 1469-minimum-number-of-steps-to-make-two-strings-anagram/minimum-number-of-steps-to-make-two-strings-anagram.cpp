class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m;
        int temp =0;
        for(int i=0; i<s.length(); i++){
            m[s[i]]++;
        }
        for(int i =0; i<t.length();i++){
            if(m[t[i]] != 0) m[t[i]]--;
            else temp++;
        }
        return temp;
    }
};