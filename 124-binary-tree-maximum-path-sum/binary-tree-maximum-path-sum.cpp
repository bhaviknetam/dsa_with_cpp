/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: int ans;
public:
    int dfs(TreeNode* node){
        if(node == nullptr) return 0;
        int sum = node->val;
        int left = dfs(node->left);
        int right = dfs(node->right);
        int temp = max({sum, sum + left, sum + right});
        ans = max({ans, sum + left + right, temp});
        return temp;
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};