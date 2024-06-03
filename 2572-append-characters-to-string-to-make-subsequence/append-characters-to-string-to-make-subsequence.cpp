class Solution {
public:
    int appendCharacters(string s, string t) {
        int start_t=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==t[start_t]){
                start_t++;
            }
        }
        return t.size()-start_t;
    }
};