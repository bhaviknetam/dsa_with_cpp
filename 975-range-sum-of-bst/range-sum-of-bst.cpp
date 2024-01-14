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
    int preorder(TreeNode* root , int low, int high){
        int sum=0;
        if(root == nullptr) return 0;
        if(root->val >= low && root->val <= high){
            sum = sum + root->val;
        }
        sum = sum + preorder(root->left, low, high) + preorder(root->right, low, high);
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = preorder(root, low , high);
        return sum;
    }
};