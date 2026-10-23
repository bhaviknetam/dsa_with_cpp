class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(n == 1) return 0;
        if(n == 2){
            if(s[0] > s[1]) return -1;
            return 0;
        }
        if(is_sorted(s.begin(), s.end())) return 0;
        char minc = 'z', maxc = 'a';
        for(auto& c:s) minc=min(minc, c), maxc=max(maxc, c);
        if(s[0]==minc || s[n-1] == maxc){
            return 1;
        }
        if(s[0]==maxc && s[n-1]==minc){
            for(int i=1;i<n-1;i++){
                if(s[i]==maxc||s[i]==minc){
                    return 2;
                }
            }
            return 3;
        }
        return 2;
    }
};