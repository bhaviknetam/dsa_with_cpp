#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int cal_sum(vector<vector<int>>& matrix, int i, int j, int dp[][100]) {
        int sum = 1e5;
        int n = matrix.size();  // Use the size of the matrix (number of rows)

        // Base case: check if out of bounds
        if (i >= n || j < 0 || j >= n) return 1e5;
        if (i == n - 1) return matrix[i][j];  // Base case: last row

        if (dp[i][j] != 1000) return dp[i][j];

        sum = min(sum, matrix[i][j] + cal_sum(matrix, i + 1, j - 1, dp));
        sum = min(sum, matrix[i][j] + cal_sum(matrix, i + 1, j, dp));
        sum = min(sum, matrix[i][j] + cal_sum(matrix, i + 1, j + 1, dp));

        return dp[i][j] = sum;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int n = matrix.size();  // Assuming all rows have the same size
        int dp[100][100];

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                dp[i][j] = 1000;
            }
        }

        for (int i = 0; i < n; i++) {
            mini = min(mini, cal_sum(matrix, 0, i, dp));
        }

        return mini;
    }
};
