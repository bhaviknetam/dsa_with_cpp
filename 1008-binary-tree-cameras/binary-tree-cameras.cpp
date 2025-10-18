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
    int ans = 0;
    
    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        if (left == 0 && right == 0) {
            return 1;
        } else if (left == 1 || right == 1) {
            ans++;
            return 2;
        } else {
            return 0;
        }
    }
    
public:
    int minCameraCover(TreeNode* root) {
        return (dfs(root) == 1 ? 1 : 0) + ans;
    }
};