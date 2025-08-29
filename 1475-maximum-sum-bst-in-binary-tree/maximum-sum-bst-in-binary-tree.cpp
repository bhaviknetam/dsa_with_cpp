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
public:
    int ans;
    struct Info{
        bool isBst;
        int sum;
        int maxVal;
        int minVal;
    };

    Info dfs(TreeNode* root){
        if(!root) return {true, 0, INT_MIN, INT_MAX};
        Info left = dfs(root->left);
        Info right = dfs(root->right);
        if(left.isBst && right.isBst && root->val>left.maxVal && root->val < right.minVal){
            int sum = left.sum + right.sum + root->val;
            ans = max(ans, sum);
            return {true, sum, max(root->val, right.maxVal), min(root->val, left.minVal)};
        }
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};