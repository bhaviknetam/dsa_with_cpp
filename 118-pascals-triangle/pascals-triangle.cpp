class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
            return {{1}};
        vector<vector<int>> ans = {{1}, {1, 1}};
        if (numRows == 2)
            return ans;
        for (int i = 2; i < numRows; i++) {
            vector<int> curr = {1};
            for (int j = 1; j < ans[i - 1].size(); j++) {
                curr.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            curr.push_back(1);
            ans.push_back(curr);
        }
        return ans;
    }
};