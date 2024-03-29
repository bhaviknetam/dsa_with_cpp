class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans="";
        int count =0;
        for(int i=0; i < s.size(); i++){
            if(s[i]=='1') count++;
        }
        int k = s.size() - count;
        while(count > 1){
            ans.push_back('1');
            count--;
        }
        while(k--){
            ans.push_back('0');
        }
        ans.push_back('1');
        return ans;
    }
};