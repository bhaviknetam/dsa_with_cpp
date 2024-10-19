class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(!s.count(n)){
            s.insert(n);
            int sum = 0;
            string s = to_string(n);
            for(int i = 0; i < s.size();i++){
                sum+=pow(s[i]-'0', 2);
            }
            n = sum;
            if(n == 1) return true;
        }
        return false;
    }
};