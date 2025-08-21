class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0, sign = 1;
        while(i < n && s[i] == ' ') i++;
        if(s[i] == '+' || s[i] == '-'){
            sign = (s[i] == '-' ? -1 : 1);
            i++;
        }
        long long num = 0;
        while(i < n && isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
            if(num * sign < INT_MIN) return INT_MIN;
            if(num * sign > INT_MAX) return INT_MAX;
            i++;
        }
        return num * sign;
    }
};