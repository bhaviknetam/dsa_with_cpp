class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count = 0;
        for (char& i : s) {
            if (i == '(') {
                count++;
                ans = max(ans, count);
            } else if (i == ')')
                count--;
             else continue;
        }
        return ans;
    }
};