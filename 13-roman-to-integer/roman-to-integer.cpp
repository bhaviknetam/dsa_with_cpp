class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10},
                        {'L', 50}, {'C', 100}, {'D',500}, {'M', 1000}};
        int sum = 0, previous = 0;
        for(int i = s.size() - 1; i>=0; i--){
            int val = m[s[i]];
            if(val >= previous){
                sum += val;
            }else{
                sum -= val;
            }
            previous = val;
        }
        return sum;
    }
};