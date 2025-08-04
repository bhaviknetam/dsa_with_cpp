class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1), curr(n, 0);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    curr[j] = 1;
                } else
                    curr[j] += curr[j - 1] + prev[j];
            }
            prev = curr;
            fill(curr.begin(), curr.end(), 0);
        }
        return prev[n - 1];
    }
};