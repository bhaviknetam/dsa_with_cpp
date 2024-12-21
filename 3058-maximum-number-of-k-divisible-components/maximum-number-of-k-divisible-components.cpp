class Solution {
private: 
    int ans;
    vector<long long> sum; // Subtree sums
    vector<vector<int>> g; // Adjacency list

public:
    long long dfs1(int node, int par, vector<int>& values) {
        long long val = values[node];
        for (int& child : g[node]) {
            if (child != par) {
                val += dfs1(child, node, values);
            }
        }
        return sum[node] = val;
    }

    void dfs2(int node, int par, int& k, long long totalSum) {
        for (int& child : g[node]) {
            if (child != par) {
                dfs2(child, node, k, totalSum);
                if (sum[child] % k == 0) {
                    ans++;
                    sum[node] -= sum[child];
                }
            }
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n == 1) return 1; // Edge case: Single node

        // Initialize variables
        sum.resize(n, 0);
        g.resize(n, vector<int>());

        // Build adjacency list
        for (auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        // First DFS: Calculate subtree sums
        long long totalSum = dfs1(0, -1, values);

        // Initialize result
        ans = 0;

        // Second DFS: Count K-divisible components
        dfs2(0, -1, k, totalSum);

        // Include the root component
        return ans + 1;
    }
};
