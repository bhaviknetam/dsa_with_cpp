class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0, j = 0;
        while(s[i] == ' ') i++;
        bool neg = (s[i] == '-' ? 1 : 0);
        if(neg || s[i] == '+') i++;
        j = i;
        while(s[i] >= '0' && s[i] <= '9') i++;
        long long num = 0;
        for(; j < i; j++){
            if(num > INT_MAX) return (neg ? INT_MIN : INT_MAX);
            num = num * 10 + (s[j] - '0');
        }
        if(num > INT_MAX) return (neg ? INT_MIN : INT_MAX);
        if(neg) num = -num;
        return num;
    }
};