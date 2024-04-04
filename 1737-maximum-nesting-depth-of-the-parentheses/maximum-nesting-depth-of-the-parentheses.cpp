class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count = 0;
        for (char& i : s) {
            if (i == '(')
                count++;
            else if (i == ')')
                count--;
            ans = max(ans, count);
        }
        return ans;
    }
};