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
    int ans = 0;
    int preorderMax(TreeNode* root){
        if(!root) return 0;
        int leftMax = preorderMax(root->left);
        int rightMax = preorderMax(root->right);
        int maxVal = max(leftMax, rightMax);
        if(root->val >= maxVal) ans++;
        return max(root->val, maxVal);
    }
    int countDominantNodes(TreeNode* root) {
        if(!root) return 0;
        preorderMax(root);
        return ans;
    }
};