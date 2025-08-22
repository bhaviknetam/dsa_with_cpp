class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string t = countAndSay(n-1);
        string ans;
        int i = 0;
        int sz = t.size();
        while(i < sz){
            int j = i;
            while(j < sz && t[j] == t[i]) j++;
            ans.push_back((j - i) + '0');
            ans.push_back(t[i]);
            i = j;
        }
        return ans;
    }
};