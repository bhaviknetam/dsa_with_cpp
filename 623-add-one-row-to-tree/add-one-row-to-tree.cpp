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
    void func(TreeNode* root, int val, int depth) {
        if (depth == 2) {
            TreeNode* temp1 = root->left;
            TreeNode* temp2 = root->right;
            TreeNode* newNode1 = new TreeNode(val);
            TreeNode* newNode2 = new TreeNode(val);
            root->left = newNode1;
            root->left->left = temp1;
            root->right = newNode2;
            root->right->right = temp2;
            return;
        }
        if (root->left)
            func(root->left, val, depth - 1);
        if (root->right)
            func(root->right, val, depth - 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        func(root, val, depth);
        return root;
    }
};