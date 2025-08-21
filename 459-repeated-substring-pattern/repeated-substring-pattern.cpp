class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n == 1) return false;
        vector<int> div = {1};
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                div.push_back(i);
                if(n / i != i) div.push_back(n/i);
            }
        }
        for(int& d : div){
            bool found = true;
            for(int i = 0; i < n; i++){
                if(s[i] != s[i % d]){
                    found = false;
                    break;
                }
            }
            if(found) return true;
        }
        return false;
    }
};