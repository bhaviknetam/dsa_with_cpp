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
private:
    int ans;
public:
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        if(ans < left + root->val + right)
            ans = left + root->val + right;
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};