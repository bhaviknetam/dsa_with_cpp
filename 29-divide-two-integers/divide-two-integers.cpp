class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool neg = (dividend < 0) ^ (divisor < 0);
        long long divid = abs((long long)dividend);
        long long divis = abs((long long)divisor);
        long long quot = 0;
        while(divid >= divis){
            long long t = divis, m = 1;
            while(divid >= (t << 1)){
                t <<= 1;
                m <<= 1;
            }
            divid -= t;
            quot += m;
        }
        return (neg ? -quot : quot);
    }
};