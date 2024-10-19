class Solution {
public:
    string invert(string s){
        for(int i = 0; i < (int)s.size(); i++){
            if(s[i]=='0') s[i]='1';
            else s[i] = '0';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 2; i <=n; i++){
            string temp = invert(s);
            reverse(temp.begin(), temp.end());
            string ans = s + "1" + temp;
            s = ans;
        }
        return s[k-1];
    }
};