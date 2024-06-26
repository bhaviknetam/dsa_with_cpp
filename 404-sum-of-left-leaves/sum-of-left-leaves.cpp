/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }
        if (root->left != nullptr)
            if (root->left->left == nullptr && root->left->right == nullptr)
                sum += root->left->val;
        if (root->left != nullptr)
            sum += sumOfLeftLeaves(root->left);
        if (root->right != nullptr) {
            sum += sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};