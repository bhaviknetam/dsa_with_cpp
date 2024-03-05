class Solution {
public:
    int minimumLength(string s) {
        int i=0, j=s.size()-1;
        char temp;
        while(i<j){
            if(s[i]==s[j]){
                temp=s[i];
                i++;
                j--;
            }
            else if(s[i]==temp){
                i++;
            }else if(s[j]==temp){
                j--;
            }
            else break;

        }
        if(s[i]==temp) return 0;
        if(j-i+1<0)return 0;
        return j-i+1;
    }
};