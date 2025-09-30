class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size();
        int n = num2.size();
        vector<int> res(m + n, 0);
        
        for (int i = 0; i < m; i++) {
            int digit1 = num1[m - 1 - i] - '0';
            for (int j = 0; j < n; j++) {
                int digit2 = num2[n - 1 - j] - '0';
                res[i + j] += digit1 * digit2;
            }
        }
        
        for (int k = 0; k < m + n - 1; k++) {
            int carry = res[k] / 10;
            res[k] %= 10;
            res[k + 1] += carry;
        }
        
        int idx = m + n - 1;
        while (idx >= 0 && res[idx] == 0) {
            idx--;
        }
        if (idx < 0) {
            return "0";
        }
        
        string ans;
        for (; idx >= 0; idx--) {
            ans += (res[idx] + '0');
        }
        return ans;
    }
};