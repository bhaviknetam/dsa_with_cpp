#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;

        // Initialize a vector to store results from 1 to n
        std::vector<int> dp(n + 1, INT_MAX);

        // 0 requires 0 squares
        dp[0] = 0;

        // Iterate from 1 to n to calculate minimum squares for each number
        for (int i = 1; i <= n; ++i) {
            // For each number, check squares from 1^2 to sqrt(i)
            for (int j = 1; j * j <= i; ++j) {
                // Update dp[i] with the minimum of current value or 1 + dp[i - j * j]
                dp[i] = std::min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }
};
