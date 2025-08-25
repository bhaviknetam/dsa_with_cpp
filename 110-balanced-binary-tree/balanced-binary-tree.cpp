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
    int checkHeight(TreeNode* root){
        if(!root) return 0;
        int lst = checkHeight(root->left);
        if(lst < 0)
            return -1;
        int rst = checkHeight(root->right);
        if(rst < 0)
            return -1;
        if(abs(rst - lst) > 1)
            return -1;
        return 1 + max(lst, rst);
    }
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) >= 0;
    }
};